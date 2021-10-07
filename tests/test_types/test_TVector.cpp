#include "twCore/Types/TVector.hpp"
#include "gtest/gtest.h"

using namespace twCore;

TEST(Test_TVector, TVector)
{
    TVector<int> intVector;
    intVector.push_back(0);
}