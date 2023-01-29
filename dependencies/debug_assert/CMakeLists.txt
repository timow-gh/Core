CPMAddPackage(
        NAME foonathan_debug_assert
        GITHUB_REPOSITORY foonathan/debug_assert
        GIT_TAG master
        GIT_SHALLOW TRUE
        OPTIONS
        "DEBUG_ASSERT_INSTALL ${${PROJECT_NAME}_INSTALL}"
)