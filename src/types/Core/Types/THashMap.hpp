#ifndef CORE_THASHMAP_HPP
#define CORE_THASHMAP_HPP

#include "absl/container/flat_hash_map.h"
#include "absl/hash/hash.h"

namespace Core
{
template <typename K, typename V>
using THashMap = absl::flat_hash_map<K, V>;
} // namespace Core

#endif // CORE_THASHMAP_HPP
