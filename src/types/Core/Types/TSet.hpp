#ifndef CORE_TSET_HPP
#define CORE_TSET_HPP

#include <set>

namespace Core
{
template <typename T, typename Alloc = std::allocator<T>>
using TSet = std::set<T, Alloc>;
}

#endif // CORE_TSET_HPP
