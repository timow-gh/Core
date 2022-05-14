add_library(Core_Types INTERFACE)

set(Core_Types_HEADERS
    Core/Types/TArray.hpp
    Core/Types/TSet.hpp
    Core/Types/TSpan.hpp
    Core/Types/TString.hpp
    Core/Types/TStringView.hpp
    Core/Types/TMap.hpp
    Core/Types/TVector.hpp
    Core/Types/THashMap.hpp)

set_target_properties(Core_Types
        PROPERTIES
        CXX_STANDARD_REQUIRED ON
        CXX_STANDARD ${CMAKE_CXX_STANDARD}
        CXX_EXTENSIONS ${CMAKE_CXX_EXTENSIONS})

set(Core_Types_CXX_STANDARD "")
get_target_property(Core_Types_CXX_STANDARD Core_Types CXX_STANDARD)
if(NOT Core_Types_CXX_STANDARD)
    message(FATAL_ERROR "CXX_STANDARD for target Core_Types not defined.")
    return()
endif()

target_include_directories(Core_Types INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>")
target_link_libraries(Core_Types INTERFACE Core::Utils nonstd::span-lite nonstd::string-view-lite)

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
