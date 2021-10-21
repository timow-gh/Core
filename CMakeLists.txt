cmake_minimum_required(VERSION 3.19)

include(FetchContent)
FetchContent_Declare(twCMakeUtils
        GIT_REPOSITORY https://github.com/timow-gh/twCMakeUtils.git
        GIT_TAG main)
FetchContent_GetProperties(twCMakeUtils)
set(lcs_twCMakeUtils "")
string(TOLOWER "twCMakeUtils" lcs_twCMakeUtils)
if (NOT ${lcs_twCMakeUtils}_POPULATED)
    FetchContent_Populate(twCMakeUtils)
    list(APPEND CMAKE_MODULE_PATH ${${lcs_twCMakeUtils}_SOURCE_DIR}/modules)
    include(CMakeHelperFunctions)
endif()

project(Core
        VERSION 0.1.0
        LANGUAGES CXX)

option(${PROJECT_NAME}_INSTALL_LIB "Enable install rule" ON)
if ((CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR))
    option(Core_BUILD_TESTS "Enable tests" ON)
else ()
    option(Core_BUILD_TESTS "Enable tests" OFF)
endif ()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

preamble()

add_subdirectory(src)

if (Core_BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif ()
