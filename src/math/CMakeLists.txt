set(Core_Math_HEADERS
        twCore/Math/Eps.hpp
        twCore/Math/Constants.hpp)

add_library(twCore_Math INTERFACE)
target_include_directories(twCore_Math INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/>)

add_library(twCore::Math ALIAS twCore_Math)
set_target_properties(twCore_Math PROPERTIES EXPORT_NAME twCoreMath)

if (twCore_INSTALL_LIB)
    install(FILES ${Core_Math_HEADERS} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${TARGET_ALIAS}")

    install(TARGETS twCore_Math
            EXPORT twCoreTargetsExportSet
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endif ()