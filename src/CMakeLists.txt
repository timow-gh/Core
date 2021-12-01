add_subdirectory(color)
add_subdirectory(core_settings)
add_subdirectory(math)
add_subdirectory(types)
add_subdirectory(utils)

if (${PROJECT_NAME}_INSTALL_LIB)
    setupExportSetInstall("Core" "CoreTargetsExportSet")
endif ()