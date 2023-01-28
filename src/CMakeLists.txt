set(project_export_set_name "${PROJECT_NAME}TargetsExportSet")

add_subdirectory(math_lib)
add_subdirectory(types_lib)
add_subdirectory(utils_lib)

setup_export_set_installation(
        ${PROJECT_NAME}
        "${project_export_set_name}"
        "${PROJECT_NAME}Config.cmake.in"
        ${PROJECT_VERSION_MAJOR} ${PROJECT_VERSION_MINOR} ${PROJECT_VERSION_PATCH}
)

