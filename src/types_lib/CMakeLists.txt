set(HEADER_FILES
        Core/Types/TArray.hpp
        Core/Types/TSet.hpp
        Core/Types/TSpan.hpp
        Core/Types/TString.hpp
        Core/Types/TStringView.hpp
        Core/Types/TMap.hpp
        Core/Types/TVector.hpp
        Core/Types/THashMap.hpp)

set(TARGET_NAME tw_core_types)
set(TARGET_ALIAS_NAME Types)

add_library(${TARGET_NAME} INTERFACE)

target_link_libraries(${TARGET_NAME} INTERFACE
        Core::Utils
        nonstd::span-lite
        nonstd::string-view-lite)

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
        OUTPUT_NAME TwCoreTypes
        EXPORT_NAME ${TARGET_ALIAS_NAME}
        )

include(Warnings)
add_warnings_and_compile_options(${TARGET_NAME} ${PROJECT_NAME}_WARNINGS_AS_ERRORS)

if (${PROJECT_NAME}_STATIC_ANALYSIS)
    include(static_analysis)
    enable_static_analysis(${TARGET_NAME} ${${PROJECT_NAME}_WARNINGS_AS_ERRORS})
endif ()

if (${PROJECT_NAME}_INSTALL)
    install(FILES ${HEADER_FILES} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${TARGET_ALIAS_NAME}"
            )

    install(TARGETS ${TARGET_NAME} string-view-lite
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

