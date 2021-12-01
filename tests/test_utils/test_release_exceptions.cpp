#include "gtest/gtest.h"
#include <Core/Utils/Assert.hpp>

TEST(Test_PostCondition, core_assert_postcondition_fail)
{
    int* ptr = nullptr;
    EXPECT_ANY_THROW(CORE_POSTCONDITION_ASSERT(ptr, "ptr is null"));
}

TEST(Test_PostCondition, core_exception_postcondition_success)
{
    int* ptr = new int(1);
    EXPECT_NO_THROW(CORE_POSTCONDITION_ASSERT(ptr, "ptr is not null"));
}

TEST(Test_PreCondition, core_assert_precondition_fail)
{
    int* ptr = nullptr;
    EXPECT_ANY_THROW(CORE_PRECONDITION_ASSERT(ptr, "ptr is null"));
}

TEST(Test_PreCondition, core_exception_precondition_success)
{
    int* ptr = new int(1);
    EXPECT_NO_THROW(CORE_PRECONDITION_ASSERT(ptr, "ptr is not null"));
}