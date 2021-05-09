#include "gtest/gtest.h"

#include "Core/Types/TVector.hpp"

using namespace Core;

TEST(Test_TVector, TVector) {
    TVector<int> intVector;
    intVector.push_back(0);
}