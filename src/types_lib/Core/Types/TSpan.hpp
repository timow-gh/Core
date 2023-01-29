#ifndef CORE_TSPAN_HPP
#define CORE_TSPAN_HPP

#include <Core/Utils/Compiler.hpp>
#include <Core/Utils/Warnings.hpp>
DISABLE_ALL_WARNINGS
#include <nonstd/span.hpp>
ENABLE_ALL_WARNINGS

namespace Core
{
CORE_CONSTEXPR size_t dynamic_extent = static_cast<size_t>(-1);

template <typename T, std::size_t SSize = dynamic_extent>
using TSpan = nonstd::span<T, SSize>;

} // namespace Core

#endif // CORE_TSPAN_HPP
