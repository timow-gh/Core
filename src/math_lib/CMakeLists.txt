set(HEADER_FILES
        Core/Math/Eps.hpp
        Core/Math/Constants.hpp)

set(TARGET_NAME tw_core_math)
set(TARGET_ALIAS_NAME Math)

add_library(${TARGET_NAME} INTERFACE ${HEADER_FILES})

target_link_libraries(${TARGET_NAME} INTERFACE Core::Utils)

add_library(${PROJECT_NAME}::${TARGET_ALIAS_NAME} ALIAS ${TARGET_NAME})

target_include_directories(${TARGET_NAME}
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>)

set(${TARGET_NAME}_MAJOR 0)
set(${TARGET_NAME}_MINOR 1)
set(${TARGET_NAME}_PATCH 0)
message(STATUS "Configuring ${TARGET_NAME} ${${TARGET_NAME}_MAJOR}.${${TARGET_NAME}_MINOR}.${${TARGET_NAME}_PATCH}")

set_target_properties(${TARGET_NAME}
        PROPERTIES
        LANGUAGE CXX
        DEBUG_POSTFIX d
        VERSION ${${TARGET_NAME}_MAJOR}.${${TARGET_NAME}_MINOR}.${${TARGET_NAME}_PATCH}
        SOVERSION ${${TARGET_NAME}_MAJOR}
        OUTPUT_NAME TwCoreMath
        EXPORT_NAME ${TARGET_ALIAS_NAME}
        )

include(warnings)
add_warnings_and_compile_options(${TARGET_NAME} ${${PROJECT_NAME}_WARNINGS_AS_ERRORS})

if (${PROJECT_NAME}_STATIC_ANALYSIS)
    include(static_analysis)
    enable_static_analysis(${TARGET_NAME} ${${PROJECT_NAME}_WARNINGS_AS_ERRORS})
endif ()

if (${PROJECT_NAME}_INSTALL)
    install(FILES ${HEADER_FILES} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${TARGET_ALIAS_NAME}"
            )

    install(TARGETS ${TARGET_NAME}
            EXPORT ${PROJECT_NAME}TargetsExportSet
            RUNTIME
            DESTINATION ${CMAKE_INSTALL_BINDIR}
            LIBRARY
            DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE
            DESTINATION ${CMAKE_INSTALL_LIBDIR}
            INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
            )
endif ()
