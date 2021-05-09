#ifndef CORE_TARRAY_HPP
#define CORE_TARRAY_HPP

#include <limits>
#include <array>

namespace Core {
constexpr std::size_t INVALID_INDEX = std::numeric_limits<std::size_t>::max();

template <typename T, std::size_t N> using TArray = std::array<T, N>;
} // namespace Core

#endif // CORE_TARRAY_HPP
