add_subdirectory(math)
add_subdirectory(types)

if (${PROJECT_NAME}_INSTALL_LIB)
    setupExportSetInstall("Core" "CoreTargetsExportSet")
endif ()