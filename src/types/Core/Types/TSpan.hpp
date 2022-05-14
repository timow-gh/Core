#ifndef CORE_TSPAN_HPP
#define CORE_TSPAN_HPP

#include <nonstd/span.hpp>

namespace Core
{
inline constexpr size_t dynamic_extent = static_cast<size_t>(-1);

template <typename T, std::size_t SSize = dynamic_extent>
using TSpan = nonstd::span<T, SSize>;

}

#endif // CORE_TSPAN_HPP
