enable_testing()

include(FetchContent)

option(INSTALL_GTEST OFF)
mark_as_advanced(BUILD_GMOCK)
mark_as_advanced(BUILD_TESTING)
mark_as_advanced(INSTALL_GTEST)

FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

mark_as_advanced(FETCHCONTENT_BASE_DIR)
mark_as_advanced(FETCHCONTENT_FULLY_DISCONNECTED)
mark_as_advanced(FETCHCONTENT_QUIET)
mark_as_advanced(FETCHCONTENT_SOURCE_DIR_GOOGLETEST)
mark_as_advanced(FETCHCONTENT_UPDATES_DISCONNECTED)
mark_as_advanced(FETCHCONTENT_UPDATES_DISCONNECTED_GOOGLETEST)

add_subdirectory(test_absl_usage)
add_subdirectory(test_math)
add_subdirectory(test_types)
