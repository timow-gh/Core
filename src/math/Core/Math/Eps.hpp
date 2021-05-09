#ifndef GLFWTESTAPP_EPS_H
#define GLFWTESTAPP_EPS_H

#include <cmath>

namespace Core {

  constexpr float_t EPS_F = 1.0E-6;
  constexpr double_t EPS_D = 1.0E-15;

  constexpr float_t ZERO_F = 0.0f;
  constexpr double_t ZERO_D = 0.0;

  template<typename T>
  struct eps_traits;

  template<>
  struct eps_traits<float_t> {
    static constexpr float_t value() { return EPS_F; };
  };

  template<>
  struct eps_traits<double_t> {
    static constexpr double_t value() { return EPS_D; };
  };

  template<typename T>
  constexpr bool isZero(T value, T eps) {
    return std::abs(value) < eps;
  }

  template<typename T>
  constexpr bool isZero(T value) {
    return isZero(value, eps_traits<T>::value());
  }

  template<typename T>
  constexpr bool isLess(T lhs, T rhs, T eps) {
    return lhs + eps < rhs;
  }

  template<typename T>
  constexpr bool isLess(T lhs, T rhs) {
    return isLess(lhs, rhs, eps_traits<T>::value());
  }

  template<typename T>
  constexpr bool isLessEq(T lhs, T rhs, T eps) {
    return !(isLess(rhs, lhs, eps));
  }

  template<typename T>
  constexpr bool isLessEq(T lhs, T rhs) {
    return isLessEq(lhs, rhs, eps_traits<T>::value());
  }

  template<typename T>
  constexpr bool isGreater(T lhs, T rhs, T eps) {
    return isLess(rhs, lhs, eps);
  }

  template<typename T>
  constexpr bool isGreater(T lhs, T rhs) {
    return isGreater(lhs, rhs, eps_traits<T>::value());
  }

  template<typename T>
  constexpr bool isGreaterEq(T lhs, T rhs, T eps) {
    return !isLess(lhs, rhs, eps);
  }

  template<typename T>
  constexpr bool isGreaterEq(T lhs, T rhs) {
    return isGreaterEq(lhs, rhs, eps_traits<T>::value());
  }

  template<typename T>
  constexpr bool isEq(T lhs, T rhs, T eps) {
    return std::abs(lhs - rhs) < eps;
  }

  template<typename T>
  constexpr bool isEq(T lhs, T rhs) {
    return isEq(lhs, rhs, eps_traits<T>::value());
  }

} // namespace Core

#endif // GLFWTESTAPP_EPS_H
