#pragma once

#include <Jakt/AKIntegration.h>

#include <AK/Checked.h>
#include <AK/Error.h>
#include <AK/RefCounted.h>
#include <AK/RefPtr.h>
#include <AK/Vector.h>

#include <Builtins/Range.h>
#include <initializer_list>
#include <stdlib.h>

namespace JaktInternal {
using namespace Jakt;

template<typename T>
class ArraySlice;

template<typename T>
class DynamicArrayStorage : public RefCounted<DynamicArrayStorage<T>> {
public:
    DynamicArrayStorage() { }

    ~DynamicArrayStorage()
    {
        shrink(0);
        free(m_elements);
    }

    bool is_empty() const { return m_size == 0; }
    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }

    ErrorOr<void> ensure_capacity(size_t capacity)
    {
        if (m_capacity >= capacity) {
            return {};
        }
        if (Checked<size_t>::multiplication_would_overflow(capacity, sizeof(T))) {
            return Error::from_errno(EOVERFLOW);
        }
        auto* new_elements = static_cast<T*>(malloc(capacity * sizeof(T)));
        if (!new_elements) {
            return Error::from_errno(ENOMEM);
        }
        for (size_t i = 0; i < m_size; ++i) {
            new (&new_elements[i]) T(move(m_elements[i]));
            m_elements[i].~T();
        }
        free(m_elements);
        m_elements = new_elements;
        m_capacity = capacity;
        return {};
    }

    ErrorOr<void> add_capacity(size_t additional_capacity_needed)
    {
        size_t available_space = m_capacity - m_size;

        // If we already have enough space, don't do anything.
        if (additional_capacity_needed < available_space)
            return {};

        // Grow the existing capacity by *at least* 25%.
        Checked<size_t> new_capacity = m_capacity;
        new_capacity += max(m_capacity / 4, additional_capacity_needed);

        if (new_capacity.has_overflow())
            return Error::from_errno(EOVERFLOW);

        TRY(ensure_capacity(new_capacity.value()));
        return {};
    }

    bool contains(T const& value) const
    {
        for (size_t i = 0; i < m_size; ++i) {
            if (Traits<T>::equals(m_elements[i], value)) {
                return true;
            }
        }
        return false;
    }

    ErrorOr<void> add_size(size_t size)
    {
        if (Checked<size_t>::addition_would_overflow(m_size, size)) {
            return Error::from_errno(EOVERFLOW);
        }
        TRY(resize(m_size + size));
        return {};
    }

    void shrink(size_t size)
    {
        if (size == m_size) {
            return;
        }
        VERIFY(size < this->size());
        for (size_t i = size; i < m_size; ++i) {
            m_elements[i].~T();
        }
        m_size = size;
    }

    ErrorOr<void> resize(size_t size)
    {
        if (size <= m_size) {
            shrink(size);
            return {};
        }
        TRY(ensure_capacity(size));
        for (size_t i = m_size; i < size; ++i) {
            new (&m_elements[i]) T();
        }
        m_size = size;
        return {};
    }

    T const& at(size_t index) const
    {
        VERIFY(index < m_size);
        return m_elements[index];
    }

    T& at(size_t index)
    {
        VERIFY(index < m_size);
        return m_elements[index];
    }

    ErrorOr<void> push(T value)
    {
        TRY(add_capacity(1));
        new (&m_elements[m_size]) T(move(value));
        ++m_size;
        return {};
    }

    ErrorOr<void> push_values(T const* values, size_t count)
    {
        TRY(add_capacity(count));
        for (size_t i = 0; i < count; ++i) {
            new (&m_elements[m_size + i]) T(values[i]);
        }
        m_size += count;
        return {};
    }

    ErrorOr<void> insert(size_t before_index, T value)
    {
        VERIFY(before_index <= m_size);
        TRY(ensure_capacity(size() + 1));
        TRY(push(move(value)));
        for (size_t i = size() - 1; i > before_index; --i)
            swap(m_elements[i], m_elements[i - 1]);
        return {};
    }

    T* unsafe_data() { return m_elements; }
    T const* unsafe_data() const { return m_elements; }

private:
    size_t m_size { 0 };
    size_t m_capacity { 0 };
    T* m_elements { nullptr };
};

template<typename T>
class ArrayIterator {
    using Storage = DynamicArrayStorage<T>;

public:
    ArrayIterator(NonnullRefPtr<Storage> storage, size_t offset, size_t size)
        : m_storage(move(storage))
        , m_offset(offset)
        , m_index(offset)
        , m_size(size)
    {
    }

    Optional<T> next()
    {
        if (m_index >= (m_offset + m_size)) {
            return {};
        }
        auto current = m_storage->at(m_index);
        ++m_index;
        return current;
    }

private:
    NonnullRefPtr<Storage> m_storage;
    size_t m_offset { 0 };
    size_t m_index { 0 };
    size_t m_size { 0 };
};

template<typename T>
class DynamicArray {
    using Storage = DynamicArrayStorage<T>;

public:
    DynamicArray(DynamicArray const&) = default;
    DynamicArray(DynamicArray&&) = default;
    DynamicArray& operator=(DynamicArray const&) = default;
    DynamicArray& operator=(DynamicArray&&) = default;
    ~DynamicArray() = default;

    DynamicArray(Vector<T>&& vector)
        : m_storage(MUST(adopt_nonnull_ref_or_enomem(new(nothrow) Storage)))
    {
        MUST(ensure_capacity(vector.size()));
        for (auto& item : vector)
            MUST(push(move(item)));
    }

    operator Span<T const>() const
    {
        return { unsafe_data(), size() };
    }

    ArrayIterator<T> iterator() const
    {
        return ArrayIterator<T> { *m_storage, 0, m_storage->size() };
    }

    static ErrorOr<DynamicArray> create_empty()
    {
        auto storage = TRY(adopt_nonnull_ref_or_enomem(new (nothrow) Storage));
        return DynamicArray { move(storage) };
    }

    static ErrorOr<DynamicArray> create_with(std::initializer_list<T> list) requires(!IsLvalueReference<T>)
    {
        auto array = TRY(create_empty());
        TRY(array.ensure_capacity(list.size()));
        for (auto& item : list)
            TRY(array.push(item));
        return array;
    }

    bool is_empty() const { return m_storage->is_empty(); }
    size_t size() const { return m_storage->size(); }
    size_t capacity() const { return m_storage->capacity(); }

    ErrorOr<void> push(T value)
    {
        TRY(m_storage->push(move(value)));
        return {};
    }

    ErrorOr<void> push_values(T const* values, size_t count)
    {
        TRY(m_storage->push_values(values, count));
        return {};
    }

    ErrorOr<void> push_values(DynamicArray<T> const& values)
    {
        TRY(m_storage->ensure_capacity(capacity() + values.size()));
        for (size_t i = 0; i < values.size(); ++i) {
            TRY(push(values.at(i)));
        }
        return {};
    }

    T const& at(size_t index) const
    {
        return m_storage->at(index);
    }

    T& at(size_t index)
    {
        return m_storage->at(index);
    }

    bool contains(T const& value) const
    {
        return m_storage->contains(value);
    }

    T const& operator[](size_t index) const { return at(index); }
    T& operator[](size_t index) { return at(index); }

    template<Integral U>
    ArraySlice<T> operator[](Range<U> range) const { return slice_range(range.start, range.end); }

    ErrorOr<void> ensure_capacity(size_t capacity)
    {
        TRY(m_storage->ensure_capacity(capacity));
        return {};
    }

    ErrorOr<void> add_capacity(size_t capacity)
    {
        TRY(m_storage->add_capacity(capacity));
        return {};
    }

    ErrorOr<void> add_size(size_t size)
    {
        TRY(m_storage->add_size(size));
        return {};
    }

    ArraySlice<T> slice_range(size_t from, size_t to) const
    {
        return slice(from, to - from);
    }

    ArraySlice<T> slice(size_t offset, size_t size) const;
    ArraySlice<T> slice(size_t offset, size_t size);

    void shrink(size_t size)
    {
        m_storage->shrink(size);
    }

    ErrorOr<void> resize(size_t size)
    {
        if (size != this->size()) {
            TRY(m_storage->resize(size));
        }
        return {};
    }

    Optional<T> pop()
    {
        if (is_empty())
            return {};
        auto value = move(at(size() - 1));
        shrink(size() - 1);
        return value;
    }

    ErrorOr<void> insert(size_t before_index, T value)
    {
        return m_storage->insert(before_index, move(value));
    }

    static ErrorOr<DynamicArray> filled(size_t size, T value)
    {
        auto array = TRY(create_empty());
        TRY(array.ensure_capacity(size));
        for (size_t i = 0; i < size; ++i) {
            TRY(array.push(value));
        }
        return array;
    }

    T* unsafe_data()
    {
        return m_storage->unsafe_data();
    }

    T const* unsafe_data() const
    {
        return m_storage->unsafe_data();
    }

    Optional<T> first() const
    {
        if (is_empty())
            return {};
        return at(0);
    }

    Optional<T> last() const
    {
        if (is_empty())
            return {};
        return at(size() - 1);
    }

private:
    explicit DynamicArray(NonnullRefPtr<Storage> storage)
        : m_storage(storage)
    {
    }

    NonnullRefPtr<Storage> m_storage;
};

template<typename T>
class ArraySlice {
public:
    ArraySlice() = default;
    ArraySlice(ArraySlice const&) = default;
    ArraySlice(ArraySlice&&) = default;
    ArraySlice& operator=(ArraySlice const&) = default;
    ArraySlice& operator=(ArraySlice&&) = default;
    ~ArraySlice() = default;

    ArraySlice(NonnullRefPtr<DynamicArrayStorage<T>> storage, size_t offset, size_t size)
        : m_storage(move(storage))
        , m_offset(offset)
        , m_size(size)
    {
        VERIFY(m_storage);

        if (m_offset >= m_storage->size()) {
            m_offset = 0;
            m_size = 0;
        } else if (m_offset + m_size >= m_storage->size()) {
            m_size = m_storage->size() - m_offset;
        }
    }

    ErrorOr<DynamicArray<T>> to_array() const
    {
        auto array = TRY(DynamicArray<T>::create_empty());
        TRY(array.ensure_capacity(size()));
        for (size_t i = 0; i < size(); ++i) {
            TRY(array.push(at(i)));
        }

        return array;
    }

    ArrayIterator<T> iterator() const
    {
        return ArrayIterator<T> { *m_storage, m_offset, size() };
    }

    bool is_empty() const { return size() == 0; }
    size_t size() const
    {
        if (!m_storage)
            return 0;
        if (m_offset + m_size > m_storage->size())
            return 0;

        return m_size;
    }

    T const& at(size_t index) const { return m_storage->at(m_offset + index); }
    T& at(size_t index) { return m_storage->at(m_offset + index); }
    T const& operator[](size_t index) const { return at(index); }
    T& operator[](size_t index) { return at(index); }

    template<Integral U>
    ArraySlice<T> operator[](Range<U> range) const { return slice_range(range.start, range.end); }

    ArraySlice<T> slice_range(size_t from, size_t to) const
    {
        return slice(from + m_offset, to - from + m_offset);
    }

    ArraySlice<T> slice(size_t offset, size_t size) const;

    bool contains(T const& value) const
    {
        for (size_t i = 0; i < m_size; ++i) {
            if (Traits<T>::equals(at(i), value)) {
                return true;
            }
        }
        return false;
    }

    Optional<T> first() const
    {
        if (is_empty())
            return {};
        return at(0);
    }

    Optional<T> last() const
    {
        if (is_empty())
            return {};
        return at(size() - 1);
    }

private:
    RefPtr<DynamicArrayStorage<T>> m_storage;
    size_t m_offset { 0 };
    size_t m_size { 0 };
};

template<typename T>
ArraySlice<T> DynamicArray<T>::slice(size_t offset, size_t size) const
{
    return { *m_storage, offset, size };
}

template<typename T>
ArraySlice<T> DynamicArray<T>::slice(size_t offset, size_t size)
{
    return { *m_storage, offset, size };
}

template<typename T>
ArraySlice<T> ArraySlice<T>::slice(size_t offset, size_t size) const
{
    return { *m_storage, offset, size };
}
}

namespace Jakt {
using JaktInternal::DynamicArray;
using JaktInternal::ArrayIterator;
using JaktInternal::ArraySlice;
}
