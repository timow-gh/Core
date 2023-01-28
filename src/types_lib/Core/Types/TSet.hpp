#ifndef CORE_TSET_HPP
#define CORE_TSET_HPP

#include <set>

namespace Core
{

template <typename T,
          typename Compare = std::less<T>,
          typename Alloc = std::allocator<T>>
using TSet = std::set<T, Compare, Alloc>;

} // namespace Core

#endif // CORE_TSET_HPP
