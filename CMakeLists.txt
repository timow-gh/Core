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
endif ()

project(Core
        VERSION 0.1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if (NOT CMAKE_CXX_STANDARD)
    message(FATAL_ERROR "CMAKE_CXX_STANDARD not defined.")
    return()
endif ()

message(STATUS "CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")

option(${PROJECT_NAME}_INSTALL_LIB "Enable install rule" ON)
if ((CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR))
    option(Core_BUILD_TESTS "Enable tests" ON)
else ()
    option(Core_BUILD_TESTS "Enable tests" OFF)
endif ()

option(Core_USE_WARNINGS "Activates all warnings as errors." OFF)
option(Core_CXX_EXCEPTIONS "Enable CXX exceptions" OFF)
option(Core_CXX_RTTI "Enable CXX rtti" OFF)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

preamble()

add_subdirectory(dependencies)
add_subdirectory(src)

if (Core_BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif ()
