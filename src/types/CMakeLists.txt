add_library(absl_interface INTERFACE)
target_link_libraries(absl_interface INTERFACE absl::base
                      absl::config
                      absl::city
                      absl::hash
                      absl::flat_hash_map
                      absl::strings)

set(Core_Types_HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/Core/Types/TArray.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Core/Types/TString.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Core/Types/TStringView.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Core/Types/TSet.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Core/Types/TMap.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Core/Types/TVector.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Core/Types/THashMap.hpp)

add_library(Core_Types INTERFACE)
target_include_directories(Core_Types INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>")
target_link_libraries(Core_Types INTERFACE absl_interface)

set(TARGET_ALIAS Types)
add_library(${PROJECT_NAME}::${TARGET_ALIAS} ALIAS Core_Types)
set_target_properties(Core_Types PROPERTIES EXPORT_NAME ${TARGET_ALIAS})

if (${PROJECT_NAME}_INSTALL_LIB)
    install(FILES ${Core_Types_HEADERS} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${TARGET_ALIAS}")

    install(TARGETS Core_Types absl_interface
            EXPORT CoreTargetsExportSet
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endif ()
