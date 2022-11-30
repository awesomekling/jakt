/*
 * Copyright (c) 2021, Ali Mohammad Pur <mpfard@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <Jakt/BitCast.h>
#include <Jakt/LinearArray.h>
#include <Jakt/StdLibExtras.h>
#include <Jakt/TypeList.h>

namespace Jakt::Detail {

template<typename T, typename IndexType, IndexType InitialIndex, typename... InTypes>
struct VariantIndexOf {
    static_assert(AK::DependentFalse<T, IndexType, InTypes...>, "Invalid VariantIndex instantiated");
};

template<typename T, typename IndexType, IndexType InitialIndex, typename InType, typename... RestOfInTypes>
struct VariantIndexOf<T, IndexType, InitialIndex, InType, RestOfInTypes...> {
    consteval IndexType operator()()
    {
        if constexpr (AK::IsSame<T, InType>)
            return InitialIndex;
        else
            return VariantIndexOf<T, IndexType, InitialIndex + 1, RestOfInTypes...> {}();
    }
};

template<typename T, typename IndexType, IndexType InitialIndex>
struct VariantIndexOf<T, IndexType, InitialIndex> {
    consteval IndexType operator()() { return InitialIndex; }
};

template<typename T, typename IndexType, typename... Ts>
consteval IndexType index_of()
{
    return VariantIndexOf<T, IndexType, 0, Ts...> {}();
}

template<typename IndexType, IndexType InitialIndex, typename... Ts>
struct Variant;

template<typename IndexType, IndexType InitialIndex, typename F, typename... Ts>
struct Variant<IndexType, InitialIndex, F, Ts...> {
    static constexpr auto current_index = VariantIndexOf<F, IndexType, InitialIndex, F, Ts...> {}();
    ALWAYS_INLINE static void delete_(IndexType id, void* data)
    {
        if (id == current_index)
            bit_cast<F*>(data)->~F();
        else
            Variant<IndexType, InitialIndex + 1, Ts...>::delete_(id, data);
    }

    ALWAYS_INLINE static void move_(IndexType old_id, void* old_data, void* new_data)
    {
        if (old_id == current_index)
            new (new_data) F(move(*bit_cast<F*>(old_data)));
        else
            Variant<IndexType, InitialIndex + 1, Ts...>::move_(old_id, old_data, new_data);
    }

    ALWAYS_INLINE static void copy_(IndexType old_id, void const* old_data, void* new_data)
    {
        if (old_id == current_index)
            new (new_data) F(*bit_cast<F const*>(old_data));
        else
            Variant<IndexType, InitialIndex + 1, Ts...>::copy_(old_id, old_data, new_data);
    }
};

template<typename IndexType, IndexType InitialIndex>
struct Variant<IndexType, InitialIndex> {
    ALWAYS_INLINE static void delete_(IndexType, void*) { }
    ALWAYS_INLINE static void move_(IndexType, void*, void*) { }
    ALWAYS_INLINE static void copy_(IndexType, void const*, void*) { }
};

struct VariantNoClearTag {
    explicit VariantNoClearTag() = default;
};
struct VariantConstructTag {
    explicit VariantConstructTag() = default;
};

template<typename T, typename Base>
struct VariantConstructors {
    ALWAYS_INLINE VariantConstructors(T&& t) requires(requires { T(move(t)); })
    {
        internal_cast().clear_without_destruction();
        internal_cast().set(move(t), VariantNoClearTag {});
    }

    ALWAYS_INLINE VariantConstructors(const T& t) requires(requires { T(t); })
    {
        internal_cast().clear_without_destruction();
        internal_cast().set(t, VariantNoClearTag {});
    }

    ALWAYS_INLINE VariantConstructors() = default;

private:
    [[nodiscard]] ALWAYS_INLINE Base& internal_cast()
    {
        // Warning: Internal type shenanigans - VariantsConstrutors<T, Base> <- Base
        //          Not the other way around, so be _really_ careful not to cause issues.
        return *static_cast<Base*>(this);
    }
};

}

namespace Jakt {

struct Empty {
};

template<typename... Ts>
struct Variant
    : public Detail::VariantConstructors<Ts, Variant<Ts...>>... {
private:
    using IndexType = AK::Conditional<sizeof...(Ts) < 255, u8, size_t>; // Note: size+1 reserved for internal value checks
    static constexpr IndexType invalid_index = sizeof...(Ts);

    template<typename T>
    static constexpr IndexType index_of() { return Detail::index_of<T, IndexType, Ts...>(); }

public:
    template<typename T>
    static constexpr bool can_contain()
    {
        return index_of<T>() != invalid_index;
    }

    IndexType index() const { return m_index; }

    template<typename... NewTs>
    friend struct Variant;

    Variant() requires(!can_contain<Empty>()) = delete;
    Variant() requires(can_contain<Empty>())
        : Variant(Empty())
    {
    }

#ifdef AK_HAS_CONDITIONALLY_TRIVIAL
    Variant(Variant const&) requires(!(IsCopyConstructible<Ts> && ...)) = delete;
    Variant(Variant const&) = default;

    Variant(Variant&&) requires(!(IsMoveConstructible<Ts> && ...)) = delete;
    Variant(Variant&&) = default;

    ~Variant() requires(!(IsDestructible<Ts> && ...)) = delete;
    ~Variant() = default;

    Variant& operator=(Variant const&) requires(!(IsCopyConstructible<Ts> && ...) || !(IsDestructible<Ts> && ...)) = delete;
    Variant& operator=(Variant const&) = default;

    Variant& operator=(Variant&&) requires(!(IsMoveConstructible<Ts> && ...) || !(IsDestructible<Ts> && ...)) = delete;
    Variant& operator=(Variant&&) = default;
#endif

    ALWAYS_INLINE Variant(Variant const& old)
#ifdef AK_HAS_CONDITIONALLY_TRIVIAL
        requires(!(AK::IsTriviallyCopyConstructible<Ts> && ...))
#endif
        : Detail::VariantConstructors<Ts, Variant<Ts...>>()...
        , m_data {}
        , m_index(old.m_index)
    {
        Helper::copy_(old.m_index, old.m_data, m_data);
    }

    // Note: A moved-from variant emulates the state of the object it contains
    //       so if a variant containing an int is moved from, it will still contain that int
    //       and if a variant with a nontrivial move ctor is moved from, it may or may not be valid
    //       but it will still contain the "moved-from" state of the object it previously contained.
    ALWAYS_INLINE Variant(Variant&& old)
#ifdef AK_HAS_CONDITIONALLY_TRIVIAL
        requires(!(AK::IsTriviallyMoveConstructible<Ts> && ...))
#endif
        : Detail::VariantConstructors<Ts, Variant<Ts...>>()...
        , m_index(old.m_index)
    {
        Helper::move_(old.m_index, old.m_data, m_data);
    }

    ALWAYS_INLINE ~Variant()
#ifdef AK_HAS_CONDITIONALLY_TRIVIAL
        requires(!(AK::IsTriviallyDestructible<Ts> && ...))
#endif
    {
        Helper::delete_(m_index, m_data);
    }

    ALWAYS_INLINE Variant& operator=(Variant const& other)
#ifdef AK_HAS_CONDITIONALLY_TRIVIAL
        requires(!(AK::IsTriviallyCopyConstructible<Ts> && ...) || !(AK::IsTriviallyDestructible<Ts> && ...))
#endif
    {
        if (this != &other) {
            if constexpr (!(AK::IsTriviallyDestructible<Ts> && ...)) {
                Helper::delete_(m_index, m_data);
            }
            m_index = other.m_index;
            Helper::copy_(other.m_index, other.m_data, m_data);
        }
        return *this;
    }

    ALWAYS_INLINE Variant& operator=(Variant&& other)
#ifdef AK_HAS_CONDITIONALLY_TRIVIAL
        requires(!(AK::IsTriviallyMoveConstructible<Ts> && ...) || !(AK::IsTriviallyDestructible<Ts> && ...))
#endif
    {
        if (this != &other) {
            if constexpr (!(AK::IsTriviallyDestructible<Ts> && ...)) {
                Helper::delete_(m_index, m_data);
            }
            m_index = other.m_index;
            Helper::move_(other.m_index, other.m_data, m_data);
        }
        return *this;
    }

    using Detail::VariantConstructors<Ts, Variant<Ts...>>::VariantConstructors...;

    template<typename T, typename StrippedT = AK::RemoveCVReference<T>>
    void set(T&& t) requires(can_contain<StrippedT>() && requires { StrippedT(forward<T>(t)); })
    {
        constexpr auto new_index = index_of<StrippedT>();
        Helper::delete_(m_index, m_data);
        new (m_data) StrippedT(forward<T>(t));
        m_index = new_index;
    }

    template<typename T, typename StrippedT = AK::RemoveCVReference<T>>
    void set(T&& t, Detail::VariantNoClearTag) requires(can_contain<StrippedT>() && requires { StrippedT(forward<T>(t)); })
    {
        constexpr auto new_index = index_of<StrippedT>();
        new (m_data) StrippedT(forward<T>(t));
        m_index = new_index;
    }

    template<typename T>
    T* get_pointer() requires(can_contain<T>())
    {
        if (index_of<T>() == m_index)
            return bit_cast<T*>(&m_data);
        return nullptr;
    }

    template<typename T>
    T& get() requires(can_contain<T>())
    {
        VERIFY(has<T>());
        return *bit_cast<T*>(&m_data);
    }

    template<typename T>
    const T* get_pointer() const requires(can_contain<T>())
    {
        if (index_of<T>() == m_index)
            return bit_cast<const T*>(&m_data);
        return nullptr;
    }

    template<typename T>
    const T& get() const requires(can_contain<T>())
    {
        VERIFY(has<T>());
        return *bit_cast<const T*>(&m_data);
    }

    template<typename T>
    [[nodiscard]] bool has() const requires(can_contain<T>())
    {
        return index_of<T>() == m_index;
    }

private:
    static constexpr auto data_size = Detail::integer_sequence_generate_LinearArray<size_t>(0, IntegerSequence<size_t, sizeof(Ts)...>()).max();
    static constexpr auto data_alignment = Detail::integer_sequence_generate_LinearArray<size_t>(0, IntegerSequence<size_t, alignof(Ts)...>()).max();
    using Helper = Detail::Variant<IndexType, 0, Ts...>;

    template<typename T_, typename U_>
    friend struct Detail::VariantConstructors;

    explicit Variant(IndexType index, Detail::VariantConstructTag)
        : Detail::VariantConstructors<Ts, Variant<Ts...>>()...
        , m_index(index)
    {
    }

    ALWAYS_INLINE void clear_without_destruction()
    {
        __builtin_memset(m_data, 0, data_size);
        m_index = invalid_index;
    }

    // Note: Make sure not to default-initialize!
    //       VariantConstructors::VariantConstructors(T) will set this to the correct value
    //       So default-constructing to anything will leave the first initialization with that value instead of the correct one.
    alignas(data_alignment) u8 m_data[data_size];
    IndexType m_index;
};

}
