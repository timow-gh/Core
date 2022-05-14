#include <Core/Types/TString.hpp>
#include <Core/Types/TStringView.hpp>
#include <gtest/gtest.h>

TEST(Test_TStringView, BasicTStringView)
{
    Core::TStringView view = "hello";
    EXPECT_TRUE("hello" == view);
}

TEST(Test_TStringView, StringViewFromString)
{
    Core::TString str("hello world.");
    Core::TStringView view{str};
    EXPECT_TRUE(view.size() == str.size());
}
