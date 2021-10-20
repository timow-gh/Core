#include "Core/Types/TSet.hpp"
#include "gtest/gtest.h"

using namespace Core;

TEST(Test_TSet, BasicSet)
{
    TSet<int> intVector;
    intVector.insert(0);
    intVector.insert(1);
    intVector.insert(0);
}