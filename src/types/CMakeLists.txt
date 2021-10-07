set(twCore_Types_HEADERS
        twCore/Types/TArray.hpp
        twCore/Types/TString.hpp
        twCore/Types/TStringView.hpp
        twCore/Types/TSet.hpp
        twCore/Types/TMap.hpp
        twCore/Types/TVector.hpp
        twCore/Types/THashMap.hpp)

add_library(twCore_Types INTERFACE)
target_include_directories(twCore_Types INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>")

add_library(twCore::Types ALIAS twCore_Types)
set_target_properties(twCore_Types PROPERTIES EXPORT_NAME twCoreTypes)

if (${PROJECT_NAME}_INSTALL_LIB)
    install(FILES ${twCore_Types_HEADERS} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${TARGET_ALIAS}")

    install(TARGETS twCore_Types
            EXPORT twCoreTargetsExportSet
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endif ()
