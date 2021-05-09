#include <utility>

#include "gtest/gtest.h"

#include "Core/Types/THashMap.hpp"
#include "Core/Types/TString.hpp"

#include "absl/hash/hash_testing.h"

using namespace Core;

TEST(AblUsage, flat_hash_map) { auto hashMap = THashMap<int, int>(); }

class UserDefinedType {
    TString m_name = "FirstName";
    TString m_surName = "Surname";

public:
    UserDefinedType() = default;
    UserDefinedType(TString name, TString surName)
        : m_name(std::move(name)), m_surName(std::move(surName)) {}

    friend bool operator==(const UserDefinedType &lhs,
                           const UserDefinedType &rhs);
    template<typename H>
    friend H AbslHashValue(H h, const UserDefinedType &m);
};

bool operator==(const UserDefinedType &lhs, const UserDefinedType &rhs) {
    return lhs.m_name == rhs.m_name && lhs.m_surName == rhs.m_surName;
}
template<typename H>
H AbslHashValue(H h, const UserDefinedType &userType) {
    return H::combine(std::move(h), userType.m_name, userType.m_surName);
}

TEST(AblUsage, Hash) {
    bool isTrue = absl::VerifyTypeImplementsAbslHashCorrectly({UserDefinedType(),
                                                               UserDefinedType("Anon", "ymous")});
    std::cout << "IsTrue: " << isTrue << std::endl;
    EXPECT_TRUE(isTrue);
}
