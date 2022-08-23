#include <Core/Types/TArray.hpp>
#include <Core/Types/TSpan.hpp>
#include <Core/Types/TVector.hpp>
#include <gtest/gtest.h>

std::size_t calcSize(Core::TSpan<int> span)
{
    return span.size();
}

TEST(Test_TSpan, SpanFromArray)
{
    Core::TArray<int, 2> arr = {0, 1};
    std::size_t size = calcSize(arr);
    EXPECT_EQ(size, 2);
}

TEST(Test_TSpan, SpanFromDynamicArray)
{
    Core::TVector<int> vec = {0, 1, 2};
    std::size_t size = calcSize({vec.begin(), vec.end()});
    EXPECT_EQ(size, 3);
}