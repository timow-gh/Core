add_executable(testEps testEps.cpp)
target_link_libraries(testEps PRIVATE gtest_main twCore::Math)
add_test(NAME testEps COMMAND testEps)