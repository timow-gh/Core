cmake_minimum_required(VERSION 3.21) # CMakePresets are supported since version 3.21

project(math_install_test
        VERSION 0.1.0
        LANGUAGES CXX)

set(TARGET_NAME test_math)
set(TARGET_ALIAS_NAME test_math)

set(${TARGET_NAME}_MAJOR 0)
set(${TARGET_NAME}_MINOR 1)
set(${TARGET_NAME}_PATCH 0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(${PROJECT_SOURCE_DIR}/cmake/project_preamble.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/setup_export_set_installation.cmake)

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


