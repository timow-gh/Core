set(Core_COLOR_HEADER
        include/Core/Color/ColorRGBA.hpp
        include/Core/Color/ColorTheme.hpp
        )

set(Core_COLOR_SOURCE
        source/Color/ColorRGBA.cpp
        source/Color/ColorRGBA.cpp
        )

add_library(Core_Color
        ${Core_COLOR_SOURCE}
        ${Core_COLOR_HEADER})
add_library(Core::Color ALIAS Core_Color)
set_target_properties(Core_Color
        PROPERTIES
        SOVERSION ${PROJECT_VERSION_MAJOR}
        VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
        DEBUG_POSTFIX d
        LINKER_LANGUAGE CXX
        EXPORT_NAME Color)

target_include_directories(Core_Color
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
        "$<BUILD_INTERFACE:${Core_BINARY_DIR}/src/color>")

target_link_libraries(Core_Color
        PUBLIC Core::Types
        INTERFACE Core::Utils)

include(GenerateExportHeader)
generate_export_header(Core_Color BASE_NAME Color)

if (${PROJECT_NAME}_INSTALL_LIB)
    install(FILES ${Core_COLOR_HEADER} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/Color")

    install(TARGETS Core_Color
            EXPORT CoreTargetsExportSet
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

    install(FILES "${Core_BINARY_DIR}/src/color/color_export.h"
            DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}")
endif ()
