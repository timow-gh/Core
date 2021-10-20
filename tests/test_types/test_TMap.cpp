#include "Core/Types/TMap.hpp"
#include "gtest/gtest.h"

using namespace Core;

TEST(Test_TMap, BasicMap)
{
    TMap<int,int> intVector;
    intVector.emplace(0,1);
    intVector.emplace(1,2);
    intVector.emplace(2,3);
}