#include "Core/Types/TString.hpp"
#include "Core/Types/TStringView.hpp"
#include "Core/Types/TVector.hpp"
#include "absl/strings/str_split.h"
#include "gtest/gtest.h"

using namespace Core;

TEST(AblUsage, flat_hash_map)
{
    TString text = "a,b,,c";
    TVector<TStringView> splitString;
    for (TStringView str: absl::StrSplit(text, ','))
        splitString.push_back(str);
}