set(Core_Utils_HEADERS
        include/Core/Utils/Assert.hpp
        include/Core/Utils/Compiler.hpp
        include/Core/Utils/Warnings.h)

add_library(Core_Utils INTERFACE ${Core_Utils_HEADERS})

target_include_directories(Core_Utils
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/generated>)
target_link_libraries(Core_Utils INTERFACE Core::Settings)

set(TARGET_ALIAS Utils)
add_library(${PROJECT_NAME}::${TARGET_ALIAS} ALIAS Core_Utils)
set_target_properties(Core_Utils PROPERTIES EXPORT_NAME ${TARGET_ALIAS})

export(TARGETS Core_Utils
        NAMESPACE Core::
        FILE "${CMAKE_BINARY_DIR}/CoreUtilsExport.cmake")

if (${PROJECT_NAME}_INSTALL_LIB)
    install(FILES ${Core_Utils_HEADERS} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${TARGET_ALIAS}")

    install(TARGETS Core_Utils
            EXPORT CoreTargetsExportSet
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endif ()
