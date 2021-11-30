add_executable(test_release_assert test_release_assert.cpp)
set_target_properties(test_release_assert PROPERTIES
        CXX_EXCEPTIONS OFF)
target_link_libraries(test_release_assert PRIVATE gtest_main Core::Utils)
add_test(NAME test_release_assert COMMAND test_release_assert)

add_executable(test_debug_assert test_debug_assert.cpp)
set_target_properties(test_debug_assert PROPERTIES
        CXX_EXCEPTIONS OFF)
target_link_libraries(test_debug_assert PRIVATE gtest_main Core::Utils)
add_test(NAME test_debug_assert COMMAND test_debug_assert)

add_executable(test_debug_exceptions test_debug_exceptions.cpp)
target_link_libraries(test_debug_exceptions PRIVATE gtest_main Core::Utils)
set_target_properties(test_debug_exceptions PROPERTIES
        CXX_EXCEPTIONS ON)
add_test(NAME test_debug_exceptions COMMAND test_debug_exceptions)

add_executable(test_release_exceptions test_release_exceptions.cpp)
target_link_libraries(test_release_exceptions PRIVATE gtest_main Core::Utils)
set_target_properties(test_release_exceptions PROPERTIES
        CXX_EXCEPTIONS ON)
add_test(NAME test_release_exceptions COMMAND test_release_exceptions)

