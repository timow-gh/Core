include(FetchContent)
add_subdirectory(debug_assert)

if (${PROJECT_NAME}_TESTS)
    add_subdirectory(googletest)
endif ()

add_subdirectory(span-lite)
add_subdirectory(stringview-lite)
