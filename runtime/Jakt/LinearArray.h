/*
 * Copyright (c) 2020, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Array.h>

namespace Jakt {

template<typename T, size_t Size>
using LinearArray = AK::Array<T, Size>;

namespace Detail{
template<typename T, size_t... Is>
constexpr auto integer_sequence_generate_LinearArray([[maybe_unused]] T const offset, AK::IntegerSequence<T, Is...>) -> LinearArray<T, sizeof...(Is)>
{
    return { { (offset + Is)... } };
}
}

}
