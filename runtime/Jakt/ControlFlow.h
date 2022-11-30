/*
 * Copyright (c) 2022, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <Jakt/Variant.h>

namespace Jakt {
template<typename Value>
struct ExplicitValue {
    ExplicitValue(Value&& v)
        : value(move(v))
    {
    }
    ExplicitValue(Value const& v)
        : value(v)
    {
    }

    Value value;
};

template<>
struct ExplicitValue<void> {
    ExplicitValue()
    {
    }
};

struct LoopBreak { };
struct LoopContinue { };

template<typename Value, typename Return>
struct ExplicitValueOrControlFlow {
    template<typename U>
    ExplicitValueOrControlFlow(ExplicitValue<U>&& v) requires(!AK::IsVoid<Value> && !AK::IsVoid<U>)
        : value(ExplicitValue<Value> { move(v.value) })
    {
    }

    ExplicitValueOrControlFlow(ExplicitValue<void>&&) requires(AK::IsVoid<Value>)
        : value(ExplicitValue<void> {})
    {
    }

    template<typename U>
    ExplicitValueOrControlFlow(U&& v) requires(!AK::IsVoid<Return> && !AK::IsSpecializationOf<U, ExplicitValue>)
        : value(Return { forward<U>(v) })
    {
    }

    ExplicitValueOrControlFlow(void) requires(AK::IsVoid<Return>)
        : value(Empty {})
    {
    }

    ExplicitValueOrControlFlow(LoopContinue)
        : value(LoopContinue {})
    {
    }

    ExplicitValueOrControlFlow(LoopBreak)
        : value(LoopBreak {})
    {
    }

    bool is_return() const
    {
        return value.template has<AK::Conditional<AK::IsVoid<Return>, AK::Empty, Return>>();
    }

    bool is_loop_break() const
    {
        return value.template has<LoopBreak>();
    }

    bool is_loop_continue() const
    {
        return value.template has<LoopContinue>();
    }

    Return release_return()
    {
        if constexpr (AK::IsVoid<Return>)
            return;
        else
            return move(value).template get<Return>();
    }
    Value release_value()

    {
        if constexpr (AK::IsVoid<Value>)
            return;
        else
            return move(move(value).template get<ExplicitValue<Value>>().value);
    }

    Jakt::Variant<AK::Conditional<AK::IsVoid<Return>, AK::Empty, Return>, ExplicitValue<Value>, LoopContinue, LoopBreak> value;
};

#define JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_RETURN_ONLY(x) ({ \
    auto&& _jakt_value = x;                                           \
    if (_jakt_value.is_return())                                      \
        return _jakt_value.release_return();                          \
    _jakt_value.release_value();                                      \
})

// XXX: `break` might not work if codegen is inside a switch block.
#define JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP(x) ({ \
    auto&& _jakt_value = x;                                       \
    if (_jakt_value.is_return())                                  \
        return _jakt_value.release_return();                      \
    else if (_jakt_value.is_loop_break())                         \
        break;                                                    \
    else if (_jakt_value.is_loop_continue())                      \
        continue;                                                 \
    _jakt_value.release_value();                                  \
})

#define JAKT_RESOLVE_EXPLICIT_VALUE_OR_CONTROL_FLOW_AT_LOOP_NESTED_MATCH(x) ({ \
    auto&& _jakt_value = x;                                                    \
    if (_jakt_value.is_return())                                               \
        return _jakt_value.release_return();                                   \
    else if (_jakt_value.is_loop_break())                                      \
        return JaktInternal::LoopBreak {};                                     \
    else if (_jakt_value.is_loop_continue())                                   \
        return JaktInternal::LoopContinue {};                                  \
    _jakt_value.release_value();                                               \
})
}
