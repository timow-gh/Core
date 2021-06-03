FetchContent_Declare(
        abseil
        GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
        GIT_TAG 20210324.1
)
set(ABSL_ENABLE_INSTALL ON)
set(BUILD_TESTING OFF)

FetchContent_MakeAvailable(abseil)

mark_as_advanced(FORCE BUILD_TESTING)
mark_as_advanced(FORCE ABSL_ENABLE_INSTALL)
mark_as_advanced(FORCE ABSL_GOOGLETEST_DOWNLOAD_URL)
mark_as_advanced(FORCE ABSL_LOCAL_GOOGLETEST_DIR)
mark_as_advanced(FORCE ABSL_USE_EXTERNAL_GOOGLETEST)
mark_as_advanced(FORCE ABSL_USE_GOOGLETEST_HEAD)
