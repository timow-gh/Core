#ifndef CORE_TARRAY_HPP
#define CORE_TARRAY_HPP

#include <array>
#include <limits>

namespace twCore
{
constexpr std::size_t INVALID_INDEX = std::numeric_limits<std::size_t>::max();

template <typename T, std::size_t N>
using TArray = std::array<T, N>;
} // namespace twCore

#endif // CORE_TARRAY_HPP
