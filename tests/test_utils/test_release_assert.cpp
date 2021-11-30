#include "gtest/gtest.h"
#include <Core/Utils/Assert.hpp>

TEST(Test_PostCondition, core_assert_postcondition_fail)
{
    int* ptr = nullptr;
    EXPECT_DEATH(CORE_ASSERT_POSTCONDITION(ptr, "ptr is null"),
                 ".*'ptr is null'.*");
}

TEST(Test_PostCondition, core_assert_postcondition_success)
{
    int* ptr = new int(1);
    EXPECT_NO_FATAL_FAILURE(CORE_ASSERT_POSTCONDITION(ptr, "ptr is not null"));
}