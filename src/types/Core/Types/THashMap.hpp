#ifndef CORE_THASHMAP_HPP
#define CORE_THASHMAP_HPP

#include <unordered_map>

namespace Core
{
// clang-format off
template <class TKey,
          class TValue,
          class Hash = std::hash<TKey>,
          class KeyEqual = std::equal_to<TKey>,
          class Allocator = std::allocator<std::pair<const TKey, TValue>>
          using THashMap = std::unordered_map<TKey, TValue>;
// clang-format on
} // namespace Core

#endif // CORE_THASHMAP_HPP
