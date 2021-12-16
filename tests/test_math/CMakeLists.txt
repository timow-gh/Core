add_executable(Test_Eps Test_Eps.cpp)
target_link_libraries(Test_Eps PRIVATE gtest_main Core::Math)
add_test(NAME Test_Eps COMMAND Test_Eps)

add_executable(Test_Constants Test_Constants.cpp)
target_link_libraries(Test_Constants PRIVATE gtest_main Core::Math)
add_test(NAME Test_Constants COMMAND Test_Constants)
