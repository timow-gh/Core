set(Core_Types_HEADERS
    Core/Types/TArray.hpp
    Core/Types/TString.hpp
    Core/Types/TStringView.hpp
    Core/Types/TSet.hpp
    Core/Types/TMap.hpp
    Core/Types/TVector.hpp
    Core/Types/THashMap.hpp)

add_library(Core_Types INTERFACE)
target_include_directories(Core_Types INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>")
target_link_libraries(Core_Types INTERFACE absl_interface)

set(TARGET_ALIAS Types)
add_library(${PROJECT_NAME}::${TARGET_ALIAS} ALIAS Core_Types)
set_target_properties(Core_Types PROPERTIES EXPORT_NAME ${TARGET_ALIAS})

if (${PROJECT_NAME}_INSTALL_LIB)
    install(FILES ${Core_Types_HEADERS} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${TARGET_ALIAS}")

    install(TARGETS Core_Types
            EXPORT CoreTargetsExportSet
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endif ()
