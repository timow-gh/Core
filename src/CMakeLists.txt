add_subdirectory(math)
add_subdirectory(types)

if (${PROJECT_NAME}_INSTALL_LIB)
    include(CMakePackageConfigHelpers)

    set(${PROJECT_NAME}_INSTALL_CMAKEDIR
            "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
            CACHE STRING "Path to install ${PROJECT_NAME} Config*.cmake files to.")
    set(${PROJECT_NAME}_MODULE_INSTALL_DIR
            "${CMAKE_INSTALL_LIBDIR}/cmake"
            CACHE STRING "Path to install ${PROJECT_NAME}'s .cmake  module files to.")

    install(EXPORT CoreTargetsExportSet
            NAMESPACE Core::
            FILE CoreTargets.cmake
            DESTINATION ${${PROJECT_NAME}_INSTALL_CMAKEDIR})

    write_basic_package_version_file(
            ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
            VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
            COMPATIBILITY SameMajorVersion)

    configure_package_config_file(
            ${PROJECT_SOURCE_DIR}/cmake/Config.cmake.in
            ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
            INSTALL_DESTINATION ${${PROJECT_NAME}_INSTALL_CMAKEDIR}
            PATH_VARS ${PROJECT_NAME}_MODULE_INSTALL_DIR
            NO_SET_AND_CHECK_MACRO
            NO_CHECK_REQUIRED_COMPONENTS_MACRO)

    install(FILES
            "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
            "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
            DESTINATION ${${PROJECT_NAME}_INSTALL_CMAKEDIR})
endif ()