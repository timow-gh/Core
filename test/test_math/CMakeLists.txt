function(create_test testName)
    add_executable(${testName} ${testName}.cpp)
    target_link_libraries(${testName} PRIVATE gtest_main Core::Math)
    add_test(NAME example_library.${testName} COMMAND ${testName})
endfunction()

create_test(Test_Constants)
create_test(Test_Eps)
