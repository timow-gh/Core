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

project(math_install_test
        VERSION 0.1.0
        LANGUAGES CXX)

set(TARGET_NAME test_core)
set(TARGET_ALIAS_NAME test_core)

set(${TARGET_NAME}_MAJOR 0)
set(${TARGET_NAME}_MINOR 1)
set(${TARGET_NAME}_PATCH 0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(setup_export_set_installation)

include(project_preamble)
project_preamble()

# Find the installed package
find_package(Core CONFIG REQUIRED)

# Use the installed package
add_executable(${TARGET_NAME} main.cpp)
target_link_libraries(${TARGET_NAME} PRIVATE Core::Math)

set_target_properties(${TARGET_NAME}
        PROPERTIES
        LANGUAGE CXX
        LINKER_LANGUAGE CXX
        DEBUG_POSTFIX d
        VERSION ${${TARGET_NAME}_MAJOR}.${${TARGET_NAME}_MINOR}.${${TARGET_NAME}_PATCH}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        OUTPUT_NAME ${TARGET_ALIAS_NAME}
        EXPORT_NAME ${TARGET_ALIAS_NAME}
        )

set(project_export_set ${TARGET_ALIAS_NAME}TargetsExportSet)

install(TARGETS
        ${TARGET_NAME}
        EXPORT ${project_export_set}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

setup_export_set_installation(
        ${PROJECT_NAME}
        ${project_export_set}
        ${TARGET_ALIAS_NAME}Config.cmake.in
        ${${TARGET_NAME}_MAJOR} ${${TARGET_NAME}_MINOR} ${${TARGET_NAME}_PATCH})


