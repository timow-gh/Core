add_subdirectory(math)
add_subdirectory(types)

if (${PROJECT_NAME}_INSTALL_LIB)
    set(write_export_set_to_binary_dir OFF)
    setupExportSetInstall(${PROJECT_NAME} "CoreTargetsExportSet" ${write_export_set_to_binary_dir})
endif ()