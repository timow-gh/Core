add_executable(test_TVector test_TVector.cpp)
target_link_libraries(test_TVector PRIVATE gtest_main Core::Types)
add_test(NAME test_TVector COMMAND test_TVector)