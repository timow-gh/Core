add_executable(test_TVector test_TVector.cpp)
target_link_libraries(test_TVector PRIVATE gtest_main Core::Types)
add_test(NAME test_TVector COMMAND test_TVector)

add_executable(test_TSet test_TSet.cpp)
target_link_libraries(test_TSet PRIVATE gtest_main Core::Types)
add_test(NAME test_TSet COMMAND test_TSet)

add_executable(test_TSpan test_TSpan.cpp)
target_link_libraries(test_TSpan PRIVATE gtest_main Core::Types)
add_test(NAME test_TSpan COMMAND test_TSpan)

add_executable(test_TStringView test_TStringView.cpp)
target_link_libraries(test_TStringView PRIVATE gtest_main Core::Types)
add_test(NAME test_TStringView COMMAND test_TStringView)

add_executable(test_TMap test_TMap.cpp)
target_link_libraries(test_TMap PRIVATE gtest_main Core::Types)
add_test(NAME test_TMap COMMAND test_TMap)

add_executable(test_THashMap test_THashMap.cpp)
target_link_libraries(test_THashMap PRIVATE gtest_main Core::Types)
add_test(NAME test_THashMap COMMAND test_THashMap)