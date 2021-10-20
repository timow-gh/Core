#ifndef CORE_THASHMAP_HPP
#define CORE_THASHMAP_HPP

#include <unordered_map>

namespace Core
{
template <class Key,
          class T,
          class Hash = std::hash<Key>,
          class KeyEqual = std::equal_to<Key>,
          class Allocator = std::allocator<std::pair<const Key, T>>>
using THashMap = std::unordered_map<Key, T, Hash, KeyEqual, Allocator>;
} // namespace Core

#endif // CORE_THASHMAP_HPP
