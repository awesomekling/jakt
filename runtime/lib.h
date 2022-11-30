#pragma once

#include <Jakt/AllOf.h>
#include <Jakt/Assertions.h>
#include <Jakt/Atomic.h>
#include <Jakt/BitCast.h>
#include <Jakt/CharacterTypes.h>
#include <Jakt/Checked.h>
#include <Jakt/Concepts.h>
#include <Jakt/Debug.h>
#include <Jakt/Error.h>
#include <Jakt/Find.h>
#include <Jakt/Format.h>
#include <Jakt/Forward.h>
#include <Jakt/Function.h>
#include <Jakt/GenericLexer.h>
#include <Jakt/HashFunctions.h>
#include <Jakt/HashTable.h>
#include <Jakt/Iterator.h>
#include <Jakt/LinearArray.h>
#include <Jakt/Memory.h>
#include <Jakt/Noncopyable.h>
#include <Jakt/NonnullRefPtr.h>
#include <Jakt/NumericLimits.h>
#include <Jakt/ControlFlow.h>
#include <Jakt/Optional.h>
#include <Jakt/Platform.h>
#include <Jakt/PrettyPrint.h>
#include <Jakt/RefCounted.h>
#include <Jakt/RefPtr.h>
#include <Jakt/ScopeGuard.h>
#include <Jakt/Span.h>
#include <Jakt/StdLibExtras.h>
#include <Jakt/String.h>
#include <Jakt/StringBuilder.h>
#include <Jakt/StringHash.h>
#include <Jakt/StringUtils.h>
#include <Jakt/StringView.h>
#include <Jakt/Traits.h>
#include <Jakt/Try.h>
#include <Jakt/Tuple.h>
#include <Jakt/TypeCasts.h>
#include <Jakt/TypeList.h>
#include <Jakt/TypedTransfer.h>
#include <Jakt/Types.h>
#include <Jakt/UnicodeUtils.h>
#include <Jakt/Variant.h>
#include <Jakt/WeakPtr.h>
#include <Jakt/Weakable.h>
#include <Jakt/kmalloc.h>
#include <Jakt/kstdio.h>

namespace JaktInternal {
template<typename T>
class Set;
}

#include <Builtins/Array.h>
#include <Builtins/Dictionary.h>
#include <Builtins/Set.h>

#include <IO/File.h>

namespace JaktInternal {

#ifdef JAKT_CONTINUE_ON_PANIC
constexpr auto continue_on_panic = true;
#else
constexpr auto continue_on_panic = false;
#endif

inline void panic(StringView message)
{
    warnln("Panic: {}", message);
    if (continue_on_panic)
        return;
    VERIFY_NOT_REACHED();
}

[[noreturn]] inline void abort()
{
    ::abort();
}

template<typename T>
inline constexpr T unchecked_add(T value, T other)
{
    return value + other;
}

template<typename T>
inline constexpr T unchecked_mul(T value, T other)
{
    return value * other;
}

template<typename T>
inline constexpr T checked_add(T value, T other)
{
    AK::Checked<T> checked = value;
    checked += other;
    if (checked.has_overflow())
        panic(MUST(Jakt::String::formatted("Overflow in checked addition '{} + {}'", value, other)));
    return checked.value_unchecked();
}

template<typename T>
inline constexpr T checked_sub(T value, T other)
{
    AK::Checked<T> checked = value;
    checked -= other;
    if (checked.has_overflow())
        panic(MUST(Jakt::String::formatted("Overflow in checked subtraction '{} - {}'", value, other)));
    return checked.value_unchecked();
}

template<typename T>
inline constexpr T checked_mul(T value, T other)
{
    AK::Checked<T> checked = value;
    checked *= other;
    if (checked.has_overflow())
        panic(MUST(Jakt::String::formatted("Overflow in checked multiplication '{} * {}'", value, other)));
    return checked.value_unchecked();
}

template<typename T>
inline constexpr T checked_div(T value, T other)
{
    AK::Checked<T> checked = value;
    checked /= other;
    if (checked.has_overflow()) {
        if (other == 0)
            panic(MUST(Jakt::String::formatted("Division by zero in checked division '{} / {}'", value, other)));
        else
            panic(MUST(Jakt::String::formatted("Overflow in checked division '{} / {}'", value, other)));
    }
    return checked.value_unchecked();
}

template<typename T>
inline constexpr T checked_mod(T value, T other)
{
    AK::Checked<T> checked = value;
    checked %= other;
    if (checked.has_overflow()) {
        if (other == 0)
            panic(MUST(Jakt::String::formatted("Division by zero in checked modulo '{} % {}'", value, other)));
        else
            panic(MUST(Jakt::String::formatted("Overflow in checked modulo '{} % {}'", value, other)));
    }
    return checked.value_unchecked();
}

template<typename T>
inline constexpr T arithmetic_shift_right(T value, size_t steps)
{
    if constexpr (AK::IsSigned<T>) {
        if constexpr (sizeof(T) == 1) {
            auto sign = (value & 0x80);
            // 8-bit variant
            return ((value >> steps) | sign);
        } else if constexpr (sizeof(T) == 2) {
            auto sign = (value & 0x8000);
            // 16-bit variant
            return ((value >> steps) | sign);
        } else if constexpr (sizeof(T) == 4) {
            auto sign = (value & 0x80000000);
            // 32-bit variant
            return ((value >> steps) | sign);
        } else if constexpr (sizeof(T) == 8) {
            auto sign = (value & 0x8000000000000000);
            // 64-bit variant
            return ((value >> steps) | sign);
        }
    } else {
        return (value >> steps);
    }
}

template<typename OutputType, typename InputType>
ALWAYS_INLINE Optional<OutputType> fallible_integer_cast(InputType input)
{
    if constexpr (AK::IsEnum<InputType>) {
        return fallible_integer_cast<OutputType>(to_underlying(input));
    } else {
        static_assert(AK::IsIntegral<InputType>);
        if (!AK::is_within_range<OutputType>(input))
            return {};
        return static_cast<OutputType>(input);
    }
}

template<typename... Ts>
void compiletime_fail(Ts...) { }

template<typename OutputType, typename InputType>
ALWAYS_INLINE constexpr OutputType infallible_integer_cast(InputType input)
{
    if constexpr (AK::IsEnum<InputType>) {
        return infallible_integer_cast<OutputType>(to_underlying(input));
    } else {
        static_assert(AK::IsIntegral<InputType>);
        if (AK::is_constant_evaluated()) {
            if (!AK::is_within_range<OutputType>(input))
                compiletime_fail("Integer cast out of range");
        } else {
            VERIFY(AK::is_within_range<OutputType>(input));
        }
        return static_cast<OutputType>(input);
    }
}

template<typename OutputType, typename InputType>
ALWAYS_INLINE constexpr OutputType as_saturated(InputType input)
{
    if constexpr (AK::IsEnum<InputType>) {
        return as_saturated<OutputType>(to_underlying(input));
    } else {
        static_assert(AK::IsIntegral<InputType>);
        if (!AK::is_within_range<OutputType>(input)) {
            if constexpr (AK::IsSigned<InputType>) {
                if (input < 0)
                    return AK::NumericLimits<OutputType>::min();
            }
            return AK::NumericLimits<OutputType>::max();
        }
        return static_cast<OutputType>(input);
    }
}

template<typename OutputType, typename InputType>
ALWAYS_INLINE constexpr OutputType as_truncated(InputType input)
{
    if constexpr (AK::IsEnum<InputType>) {
        return as_truncated<OutputType>(to_underlying(input));
    } else {
        static_assert(AK::IsIntegral<InputType>);
        return static_cast<OutputType>(input);
    }
}

inline Jakt::String ___jakt_get_target_triple_string()
{
#ifdef __JAKT_BUILD_TARGET
    return Jakt::String(__JAKT_BUILD_TARGET);
#else
// Pure guesswork.
#   if defined(_WIN64)
    return Jakt::String("x86_64-pc-windows-msvc");
#   elif defined(_WIN32)
    return Jakt::String("i686-pc-windows-msvc");
#   elif defined(__linux__)
    return Jakt::String("x86_64-pc-linux-gnu");
#   elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
    return Jakt::String("x86_64-pc-bsd-unknown");
#   elif defined(__APPLE__)
#       if defined (__arm64__)
            return Jakt::String("arm64-apple-darwin-unknown");
#       else
            return Jakt::String("x86_64-apple-darwin-unknown");
#       endif
#   elif defined(__unix__)
    return Jakt::String("x86_64-pc-unix-unknown");
#   elif defined(__serenity__)
    return Jakt::String("unknown-pc-serenity-serenity");
#   else
    return Jakt::String("unknown-unknown-unknown-unknown");
#   endif
#endif
}

template<typename T>
struct _RemoveRefPtr {
    using Type = T;
};

template<typename T>
struct _RemoveRefPtr<NonnullRefPtr<T>> {
    using Type = T;
};

template<typename T>
using RemoveRefPtr = typename _RemoveRefPtr<AK::RemoveCVReference<T>>::Type;

template<typename T>
ALWAYS_INLINE decltype(auto) deref_if_ref_pointer(T&& value)
{
    if constexpr (AK::IsSpecializationOf<AK::RemoveCVReference<T>, NonnullRefPtr>)
        return static_cast<AK::CopyConst<AK::RemoveReference<T>, RemoveRefPtr<T>>&>(*value);
    else
        return static_cast<AK::Conditional<AK::IsRvalueReference<T>, AK::RemoveReference<T>, T>>(value);
}

}

namespace Jakt {
using JaktInternal::abort;
using JaktInternal::as_saturated;
using JaktInternal::as_truncated;
using JaktInternal::fallible_integer_cast;
using JaktInternal::infallible_integer_cast;
using JaktInternal::Range;
using JaktInternal::unchecked_add;
using JaktInternal::unchecked_mul;
using JaktInternal::___jakt_get_target_triple_string;
}

// We place main in a separate namespace to ensure it has access to the same identifiers as other functions
namespace Jakt {
ErrorOr<int> main(Array<String>);
}
