add_executable(Test_ReleaseAssert Test_ReleaseAssert.cpp)
set_target_properties(Test_ReleaseAssert PROPERTIES
        CXX_EXCEPTIONS OFF)
target_link_libraries(Test_ReleaseAssert PRIVATE gtest_main Core::Utils)
add_test(NAME Test_ReleaseAssert COMMAND Test_ReleaseAssert)

add_executable(Test_DebugAssert Test_DebugAssert.cpp)
set_target_properties(Test_DebugAssert PROPERTIES
        CXX_EXCEPTIONS OFF)
target_link_libraries(Test_DebugAssert PRIVATE gtest_main Core::Utils)
add_test(NAME Test_DebugAssert COMMAND Test_DebugAssert)

add_executable(Test_DebugExceptions Test_DebugExceptions.cpp)
target_link_libraries(Test_DebugExceptions PRIVATE gtest_main Core::Utils)
set_target_properties(Test_DebugExceptions PROPERTIES
        CXX_EXCEPTIONS ON)
add_test(NAME Test_DebugExceptions COMMAND Test_DebugExceptions)

add_executable(Test_ReleaseExceptions Test_ReleaseExceptions.cpp)
target_link_libraries(Test_ReleaseExceptions PRIVATE gtest_main Core::Utils)
set_target_properties(Test_ReleaseExceptions PROPERTIES
        CXX_EXCEPTIONS ON)
add_test(NAME Test_ReleaseExceptions COMMAND Test_ReleaseExceptions)

