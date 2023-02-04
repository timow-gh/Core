cmake_minimum_required(VERSION 3.21) # CMakePresets are supported since version 3.21

include(FetchContent)
FetchContent_Declare(twCMakeUtils
        GIT_REPOSITORY https://github.com/timow-gh/twCMakeUtils.git
        GIT_TAG main)
FetchContent_GetProperties(twCMakeUtils)
set(lcs_twCMakeUtils "")
string(TOLOWER "twCMakeUtils" lcs_twCMakeUtils)
if (NOT ${lcs_twCMakeUtils}_POPULATED)
    FetchContent_Populate(twCMakeUtils)

    # Adding CPM to the project
    set(utils_cmake_modules_path ${${lcs_twCMakeUtils}_SOURCE_DIR}/modules)
    include(${utils_cmake_modules_path}/CPM.cmake)
    if (NOT CPM_SOURCE_CACHE AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/CPMSourceVariable.cmake")
        include(CPMSourceVariable.cmake)
    endif ()

    if (NOT CPM_SOURCE_CACHE)
        message(AUTHOR_WARNING "CPM_SOURCE_CACHE not set. The source files are downloaded for every build. This is not recommended.
        Set the CPM_SOURCE_CACHE variable to a directory of your choice to cache the cloned git repositories.
        Set the CPM_SOURCE_CACHE variable in CPMSourceVariable.cmake to keep your paths private.")
    endif ()

    list(APPEND CMAKE_MODULE_PATH ${utils_cmake_modules_path})
endif ()

project(Core
        VERSION 0.1.0
        LANGUAGES CXX)

# Add CPM to the project, so that subprojects can load the dependencies of this project
include(${${lcs_twCMakeUtils}_SOURCE_DIR}/modules/CPM.cmake)

# Make all modules available to this project and other projects that consume this project by
# adding the cmake directory to the CMAKE_MODULE_PATH
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(setup_export_set_installation)
include(project_preamble)
project_preamble()

if ((CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR))
    set(IS_TOP_LEVEL_PROJECT TRUE)
else ()
    set(IS_TOP_LEVEL_PROJECT FALSE)
endif ()
message(STATUS "IS_TOP_LEVEL_PROJECT: ${IS_TOP_LEVEL_PROJECT}")

if (IS_TOP_LEVEL_PROJECT)
    option(${PROJECT_NAME}_USE_SCCACHE "Use sccache" ON)
    option(${PROJECT_NAME}_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" ON)
    option(${PROJECT_NAME}_STATIC_ANALYSIS "" ON)
    option(${PROJECT_NAME}_TESTS "Build tests" ON)
else ()
    option(${PROJECT_NAME}_USE_SCCACHE "Use sccache" OFF)
    option(${PROJECT_NAME}_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
    option(${PROJECT_NAME}_STATIC_ANALYSIS "" OFF)
    option(${PROJECT_NAME}_TESTS "" OFF)
endif ()
# It is possible to exclude this project from installation by setting the following option to OFF.
# This is useful if you want to use this project as a subproject in another project.
option(${PROJECT_NAME}_INSTALL "Install project targets" ON)

if (${PROJECT_NAME}_USE_SCCACHE)
    if (NOT "${CMAKE_GENERATOR}" STREQUAL "Ninja")
        message(AUTHOR_WARNING "sccache is only testet with the generator Ninja. Setting ${PROJECT_NAME}_USE_SCCACHE to OFF.")
        set(${PROJECT_NAME}_USE_SCCACHE OFF CACHE BOOL "" FORCE)
    else ()
        find_program(CCACHE_PROGRAM sccache)
        if (CCACHE_PROGRAM)
            # Makefile Generators and the Ninja generator prefix compiler commands with the given launcher command line.
            # This is intended to allow launchers to intercept build problems with high granularity. Other generators ignore
            # this property because their underlying build systems provide no hook to wrap individual commands with a launcher.
            set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
            set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")

            include(sccache_setup)
            fix_msvc_ninja_compile_flags()
        else ()
            message(AUTHOR_WARNING "sccache not found. Please install it or disable USE_SCCACHE")
        endif ()
    endif ()
endif ()

message(STATUS "${PROJECT_NAME}_USE_SCCACHE: ${${PROJECT_NAME}_USE_SCCACHE}")
message(STATUS "${PROJECT_NAME}_WARNINGS_AS_ERRORS: ${${PROJECT_NAME}_WARNINGS_AS_ERRORS}")
message(STATUS "${PROJECT_NAME}_STATIC_ANALYSIS: ${${PROJECT_NAME}_STATIC_ANALYSIS}")

if (CMAKE_CXX_STANDARD)
    if (CMAKE_CXX_STANDARD LESS 14)
        message(FATAL_ERROR "LinAl requires C++14 or greater. CMAKE_CXX_STANDARD is set to ${CMAKE_CXX_STANDARD}.")
    endif ()
else ()
    message(FATAL_ERROR "CMAKE_CXX_STANDARD is not set. LinAl requires C++14 or greater.")
endif ()

add_subdirectory(dependencies)

add_subdirectory(src)

if (${PROJECT_NAME}_TESTS)
    include(CTest)
    # "This command should be in the source directory root because ctest expects to find a test
    # file in the build directory root.", CMake docs
    enable_testing()
    add_subdirectory(test)
endif ()

