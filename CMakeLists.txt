cmake_minimum_required(VERSION 3.19)

include(FetchContent)
FetchContent_Declare(twCMakeUtils
        GIT_REPOSITORY https://github.com/timow-gh/twCMakeUtils.git
        GIT_TAG main)
FetchContent_GetProperties(twCMakeUtils)
if(NOT twCMakeUtils_POPULATED)
    set(lcs_twCMakeUtils "")
    string(TOLOWER "twCMakeUtils" lcs_twCMakeUtils)
    FetchContent_Populate(twCMakeUtils)
    list(APPEND CMAKE_MODULE_PATH ${${lcs_twCMakeUtils}_SOURCE_DIR}/modules)
    include(CMakeHelperFunctions)
endif()

project(Core
        VERSION 0.1.0
        LANGUAGES CXX)

option(${PROJECT_NAME}_INSTALL_LIB "Enable install rule" ON)
if ((CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR))
    option(${PROJECT_NAME}_BUILD_TESTS "Enable tests" ON)
else ()
    option(${PROJECT_NAME}_BUILD_TESTS "Enable tests" OFF)
endif ()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

# TODO Enable CMAKE_CXX_STANDARD >= 11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

preamble()

# abseil has an issue for DSOs with default visibilty=hidden
# https://github.com/abseil/abseil-cpp/issues/225
set(CMAKE_CXX_VISIBILITY_PRESET default)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 0)

add_subdirectory(dependencies)

add_subdirectory(src)

if (${PROJECT_NAME}_BUILD_TESTS)
    include(CTest)
    add_subdirectory(tests)
endif ()

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_subdirectory(packaging)
endif ()


