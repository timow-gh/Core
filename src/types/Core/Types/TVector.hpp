#ifndef CORE_TVECTOR_HPP
#define CORE_TVECTOR_HPP

#include <vector>

namespace Core {
template <typename T, typename Alloc = std::allocator<T>>
using TVector = std::vector<T, Alloc>;
}

#endif // CORE_TVECTOR_HPP
