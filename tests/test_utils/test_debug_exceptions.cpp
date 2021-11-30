#include "gtest/gtest.h"

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <Core/Utils/Assert.hpp>

TEST(Test_PostCondition, core_debug_assert_postcondition_fail)
{
    int* ptr = nullptr;
    EXPECT_ANY_THROW(CORE_DEBUG_ASSERT_POSTCONDITION(ptr, "ptr is null"));
}

TEST(Test_PostCondition, core_debug_assert_postcondition_success)
{
    int* ptr = new int(1);
    EXPECT_NO_FATAL_FAILURE(
        CORE_DEBUG_ASSERT_POSTCONDITION(ptr, "ptr is not null"));
}

TEST(Test_PreCondition, core_debug_assert_precondition_fail)
{
    int* ptr = nullptr;
    EXPECT_ANY_THROW(CORE_DEBUG_ASSERT_PRECONDITION(ptr, "ptr is null"));
}

TEST(Test_PreCondition, core_debug_assert_precondition_success)
{
    int* ptr = new int(1);
    EXPECT_NO_FATAL_FAILURE(
        CORE_DEBUG_ASSERT_PRECONDITION(ptr, "ptr is not null"));
}