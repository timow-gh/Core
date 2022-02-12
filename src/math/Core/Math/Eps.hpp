#ifndef CORE_EPS_H
#define CORE_EPS_H

#include <Core/Utils/Compiler.hpp>
#include <cmath>

namespace Core
{

CORE_CONSTEXPR float_t EPS_F = 1.0E-6;
CORE_CONSTEXPR double_t EPS_D = 1.0E-15;

CORE_CONSTEXPR float_t ZERO_F = 0.0f;
CORE_CONSTEXPR double_t ZERO_D = 0.0;

template <typename T>
struct eps_traits;

template <>
struct eps_traits<float_t>
{
    static CORE_CONSTEXPR float_t value() { return EPS_F; };
};

template <>
struct eps_traits<double_t>
{
    static CORE_CONSTEXPR double_t value() { return EPS_D; };
};

template <typename T>
CORE_CONSTEXPR bool isZero(T value, T eps)
{
    return std::abs(value) < eps;
}

template <typename T>
CORE_CONSTEXPR bool isZero(T value)
{
    return isZero(value, eps_traits<T>::value());
}

template <typename T>
CORE_CONSTEXPR bool isLess(T lhs, T rhs, T eps)
{
    return lhs + eps < rhs;
}

template <typename T>
CORE_CONSTEXPR bool isLess(T lhs, T rhs)
{
    return isLess(lhs, rhs, eps_traits<T>::value());
}

template <typename T>
CORE_CONSTEXPR bool isLessEq(T lhs, T rhs, T eps)
{
    return !(isLess(rhs, lhs, eps));
}

template <typename T>
CORE_CONSTEXPR bool isLessEq(T lhs, T rhs)
{
    return isLessEq(lhs, rhs, eps_traits<T>::value());
}

template <typename T>
CORE_CONSTEXPR bool isGreater(T lhs, T rhs, T eps)
{
    return isLess(rhs, lhs, eps);
}

template <typename T>
CORE_CONSTEXPR bool isGreater(T lhs, T rhs)
{
    return isGreater(lhs, rhs, eps_traits<T>::value());
}

template <typename T>
CORE_CONSTEXPR bool isGreaterEq(T lhs, T rhs, T eps)
{
    return !isLess(lhs, rhs, eps);
}

template <typename T>
CORE_CONSTEXPR bool isGreaterEq(T lhs, T rhs)
{
    return isGreaterEq(lhs, rhs, eps_traits<T>::value());
}

template <typename T>
CORE_CONSTEXPR bool isEq(T lhs, T rhs, T eps)
{
    return std::abs(lhs - rhs) < eps;
}

template <typename T>
CORE_CONSTEXPR bool isEq(T lhs, T rhs)
{
    return isEq(lhs, rhs, eps_traits<T>::value());
}

} // namespace Core

#endif // CORE_EPS_H
