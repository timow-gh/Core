#include "Core/Types/TVector.hpp"
#include "gtest/gtest.h"

using namespace Core;

TEST(Test_TVector, TVector)
{
    TVector<int> intVector;
    intVector.push_back(0);
}