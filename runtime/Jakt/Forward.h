/*
 * Copyright (c) 2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Forward.h>

namespace Jakt {

using AK::Atomic;
using AK::Bitmap;
using AK::Bytes;
using AK::Error;
using AK::ErrorOr;
using AK::Function;
using AK::GenericLexer;
using AK::HashMap;
using AK::HashTable;
using AK::NonnullRefPtr;
using AK::Optional;
using AK::OrderedHashMap;
using AK::OrderedHashTable;
using AK::ReadonlyBytes;
using AK::RefPtr;
using AK::SimpleIterator;
using AK::Span;
using AK::Traits;
using AK::WeakPtr;

template<typename T, size_t Size>
using LinearArray = AK::Array<T, Size>;

}
