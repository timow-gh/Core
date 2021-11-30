#[[
    Enable or disable exceptions and rtti for the interface library core_exceptions_rtti_interface.
    All core libraries link to core_exceptions_rtti_interface.
]]

set_property(GLOBAL PROPERTY CXX_EXCEPTIONS ON)
set_property(GLOBAL PROPERTY CXX_RTTI ON)

add_library(core_exceptions_rtti_interface INTERFACE)

if (MSVC)
    set(purgelist
            "/EHsc"
            "/GR"
            "/Gm-"
            "-fms-extensions"
            "-fms-compatibility"
            #"-Wall"
            "-frtti"
            "-fexceptions"
            "-gline-tables-only"
            "-fno-inline"
            #"-O0"
            )
    foreach (flag
            CMAKE_C_FLAGS CMAKE_CXX_FLAGS
            CMAKE_C_FLAGS_DEBUG CMAKE_CXX_FLAGS_DEBUG
            CMAKE_C_FLAGS_RELEASE CMAKE_CXX_FLAGS_RELEASE
            CMAKE_C_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_MINSIZEREL
            CMAKE_C_FLAGS_RELWITHDEBINFO CMAKE_CXX_FLAGS_RELWITHDEBINFO
            )
        foreach (item ${purgelist})
            string(REPLACE "${item}" "" ${flag} "${${flag}}")
        endforeach ()
        string(REPLACE "-O0" "/O0" ${flag} "${${flag}}")
        string(REPLACE "-O1" "/O1" ${flag} "${${flag}}")
        string(REPLACE "-O2" "/O2" ${flag} "${${flag}}")
    endforeach ()
    target_compile_options(core_exceptions_rtti_interface INTERFACE
            $<$<STREQUAL:$<TARGET_PROPERTY:CXX_EXCEPTIONS>,ON>:/EHsc>
            $<$<STREQUAL:$<TARGET_PROPERTY:CXX_RTTI>,OFF>:/GR->)
else ()
    target_compile_options(core_exceptions_rtti_interface INTERFACE
            $<$<COMPILE_LANGUAGE:CXX>:$<$<STREQUAL:$<TARGET_PROPERTY:CXX_EXCEPTIONS>,ON>:-fexceptions>>
            $<$<COMPILE_LANGUAGE:CXX>:$<$<STREQUAL:$<TARGET_PROPERTY:CXX_RTTI>,ON>:-frtti>>
            $<$<COMPILE_LANGUAGE:CXX>:$<$<STREQUAL:$<TARGET_PROPERTY:CXX_EXCEPTIONS>,OFF>:-fno-exceptions>>
            $<$<COMPILE_LANGUAGE:CXX>:$<$<STREQUAL:$<TARGET_PROPERTY:CXX_RTTI>,OFF>:-fno-rtti>>
            )
endif ()

target_compile_definitions(core_exceptions_rtti_interface INTERFACE
        $<$<STREQUAL:$<TARGET_PROPERTY:CXX_EXCEPTIONS>,ON>:CORE_HAS_CXX_EXCEPTIONS>)

install(TARGETS core_exceptions_rtti_interface
        EXPORT CoreTargetsExportSet)