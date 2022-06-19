#ifndef CORE_TSPAN_HPP
#define CORE_TSPAN_HPP

#include <Core/Utils/Compiler.hpp>
#include <nonstd/span.hpp>

namespace Core
{
inline CORE_CONSTEXPR size_t dynamic_extent = static_cast<size_t>(-1);

template <typename T, std::size_t SSize = dynamic_extent>
using TSpan = nonstd::span<T, SSize>;

} // namespace Core

#endif // CORE_TSPAN_HPP
