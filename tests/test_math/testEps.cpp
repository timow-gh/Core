#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "gtest/gtest.h"

#include "Core/Math/Eps.hpp"

using namespace Core;

TEST(Test_Eps, isZeroFloat) {
  float_t value = 0.0;
  EXPECT_TRUE(isZero(value));
  EXPECT_FALSE(isZero(value + eps_traits<float_t>::value()));
  EXPECT_FALSE(isZero(value - eps_traits<float_t>::value()));
}

TEST(Test_Eps, isZeroDouble) {
  double_t value = 0.0;
  EXPECT_TRUE(isZero(value));
  EXPECT_FALSE(isZero(value + eps_traits<double_t>::value()));
  EXPECT_FALSE(isZero(value - eps_traits<double_t>::value()));
}

TEST(Test_Eps, isLessFloat) {
  float_t lhs = 0.0f;
  float_t rhs = eps_traits<float_t>::value();
  EXPECT_FALSE(isLess(lhs, rhs));
  EXPECT_TRUE(isLess(lhs - eps_traits<float_t>::value(), rhs));
}

TEST(Test_Eps, isLessDouble) {
  double_t lhs = 0.0f;
  double_t rhs = eps_traits<double_t>::value();
  EXPECT_FALSE(isLess(lhs, rhs));
  EXPECT_TRUE(isLess(lhs - eps_traits<double_t>::value(), rhs));
}

TEST(Test_Eps, isLessEqFloat) {
  float_t lhs = 0.0f;
  float_t rhs = eps_traits<float_t>::value();
  EXPECT_TRUE(isLessEq(lhs, rhs));
  EXPECT_TRUE(isLessEq(lhs + eps_traits<float_t>::value(), rhs));
  EXPECT_FALSE(isLessEq(lhs + 1.1f * eps_traits<float_t>::value(), 0.0f));
}

TEST(Test_Eps, isLessEqDouble) {
  double_t lhs = 0.0;
  double_t rhs = eps_traits<double_t>::value();
  EXPECT_TRUE(isLessEq(lhs, rhs));
  EXPECT_TRUE(isLessEq(lhs + eps_traits<double_t>::value(), rhs));
  EXPECT_FALSE(isLessEq(lhs + 1.1 * eps_traits<double_t>::value(), 0.0));
}

TEST(Test_Eps, isGreaterFloat) {
  float_t lhs = 0.0f;
  EXPECT_TRUE(isGreater(lhs, -1.1f * eps_traits<float_t>::value()));
  EXPECT_FALSE(isGreater(lhs, eps_traits<float_t>::value()));
}

TEST(Test_Eps, isGreaterDouble) {
  double_t lhs = 0.0f;
  EXPECT_TRUE(isGreater(lhs, -1.1f * eps_traits<double_t>::value()));
  EXPECT_FALSE(isGreater(lhs, eps_traits<double_t>::value()));
}

TEST(Test_Eps, isGreaterEqFloat) {
  float_t zeroVal = 0.0f;
  float_t eps = eps_traits<float_t>::value();
  EXPECT_TRUE(isGreaterEq(zeroVal, eps));
  EXPECT_TRUE(isGreaterEq(zeroVal + eps, eps));
  EXPECT_TRUE(isGreaterEq(zeroVal + 2.0f * eps, eps));
  EXPECT_FALSE(isGreaterEq(zeroVal, 1.1f * eps));
}

TEST(Test_Eps, isGreaterEqDouble) {
  double_t zeroVal = 0.0;
  double_t eps = eps_traits<double_t>::value();
  EXPECT_TRUE(isGreaterEq(zeroVal, eps));
  EXPECT_TRUE(isGreaterEq(zeroVal + eps, eps));
  EXPECT_TRUE(isGreaterEq(zeroVal + 2.0 * eps, eps));
  EXPECT_FALSE(isGreaterEq(zeroVal, 1.1 * eps));
}

TEST(Test_Eps, isEqualFloat) {
  float_t zeroVal = 0.0f;
  float_t eps = eps_traits<float_t>::value();
  EXPECT_TRUE(isEq(zeroVal, zeroVal));
  EXPECT_TRUE(isEq(zeroVal, 0.5f * eps));
  EXPECT_FALSE(isEq(zeroVal, eps));
  EXPECT_FALSE(isEq(zeroVal, 1.0f));
}

TEST(Test_Eps, isEqualDouble) {
  double_t zeroVal = 0.0;
  double_t eps = eps_traits<double_t>::value();
  EXPECT_TRUE(isEq(zeroVal, zeroVal));
  EXPECT_TRUE(isEq(zeroVal, 0.5 * eps));
  EXPECT_FALSE(isEq(zeroVal, eps));
  EXPECT_FALSE(isEq(zeroVal, 1.0));
}

#pragma clang diagnostic pop