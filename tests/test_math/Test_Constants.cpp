#include <Core/Math/Constants.hpp>
#include <gtest/gtest.h>
#include <cmath>

using namespace Core;

TEST(PI, AsDouble)
{
    double_t piDouble = PI<double_t>;
    EXPECT_DOUBLE_EQ(piDouble, 3.141592653589793);
}

TEST(PI_HALF, AsDouble)
{
    double_t piHalfDouble = PI_HALF<double_t>;
    EXPECT_DOUBLE_EQ(piHalfDouble, 1.570796326794896);
}

TEST(PI_2, AsDouble)
{
    double_t piTwoDouble = PI_2<double_t>;
    EXPECT_DOUBLE_EQ(piTwoDouble, 6.283185307179586);
}

TEST(PI, AsFloat)
{
    float_t piFloat = PI<float_t>;
    EXPECT_FLOAT_EQ(piFloat, 3.1415927410125732);
}

TEST(PI_HALF, AsFloat)
{
    float_t piHalfFloat = PI_HALF<float_t>;
    EXPECT_FLOAT_EQ(piHalfFloat, 1.570796326794896);
}

TEST(PI_2, AsFloat)
{
    float_t piTwoFloat = PI_2<float_t>;
    EXPECT_FLOAT_EQ(piTwoFloat, 6.283185307179586);
}
