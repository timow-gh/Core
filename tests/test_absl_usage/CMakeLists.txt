add_executable(testAbslStrings testAbslStrings.cpp)
target_link_libraries(testAbslStrings PRIVATE gtest_main gmock Core::Types)
add_test(NAME Test_AbslStrings COMMAND testAbslStrings)

add_executable(testAbslUsage testAbslUsage.cpp)
target_link_libraries(testAbslUsage PRIVATE gtest_main gmock Core::Types)
add_test(NAME testAbslUsage COMMAND testAbslUsage)
