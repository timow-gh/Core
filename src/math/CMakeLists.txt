set(Core_Math_HEADERS
        Core/Math/Eps.hpp
        Core/Math/Constants.hpp)

add_library(Core_Math INTERFACE)
target_include_directories(Core_Math INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/>)
target_link_libraries(Core_Math INTERFACE Core::Utils)

set(TARGET_ALIAS Math)
add_library(${PROJECT_NAME}::${TARGET_ALIAS} ALIAS Core_Math)
set_target_properties(Core_Math PROPERTIES EXPORT_NAME ${TARGET_ALIAS})

if (${PROJECT_NAME}_INSTALL_LIB)
    install(FILES ${Core_Math_HEADERS} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${TARGET_ALIAS}")

    install(TARGETS Core_Math
            EXPORT CoreTargetsExportSet
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endif ()