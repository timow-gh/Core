#ifndef CORE_TMAP_HPP
#define CORE_TMAP_HPP

#include <map>

namespace Core
{
template <typename K,
          typename T,
          typename Cmp = std::less<K>,
          typename Alloc = std::allocator<std::pair<const K, T>>>
using TMap = std::map<K, T, Cmp, Alloc>;
}

#endif // CORE_TMAP_HPP
