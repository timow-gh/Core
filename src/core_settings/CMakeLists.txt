#[[
    Enable or disable exceptions and rtti for the interface library Core_Settings.
    All core libraries link to Core_Settings.

    Handeling msvc exception and rtti flags using the CMake file of
    https://github.com/ned14/status-code
    as a template.
]]

set_property(GLOBAL PROPERTY CXX_EXCEPTIONS ON)
set_property(GLOBAL PROPERTY CXX_RTTI ON)

add_library(Core_Settings INTERFACE)
add_library(Core::Settings ALIAS Core_Settings)

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
    target_compile_options(Core_Settings INTERFACE
            $<$<STREQUAL:$<TARGET_PROPERTY:CXX_EXCEPTIONS>,ON>:/EHsc>
            $<$<STREQUAL:$<TARGET_PROPERTY:CXX_RTTI>,OFF>:/GR->)
else ()
    target_compile_options(Core_Settings INTERFACE
            $<$<COMPILE_LANGUAGE:CXX>:$<$<STREQUAL:$<TARGET_PROPERTY:CXX_EXCEPTIONS>,ON>:-fexceptions>>
            $<$<COMPILE_LANGUAGE:CXX>:$<$<STREQUAL:$<TARGET_PROPERTY:CXX_RTTI>,ON>:-frtti>>
            $<$<COMPILE_LANGUAGE:CXX>:$<$<STREQUAL:$<TARGET_PROPERTY:CXX_EXCEPTIONS>,OFF>:-fno-exceptions>>
            $<$<COMPILE_LANGUAGE:CXX>:$<$<STREQUAL:$<TARGET_PROPERTY:CXX_RTTI>,OFF>:-fno-rtti>>
            )
endif ()

target_compile_definitions(Core_Settings INTERFACE
        $<$<STREQUAL:$<TARGET_PROPERTY:CXX_EXCEPTIONS>,ON>:CORE_HAS_CXX_EXCEPTIONS>
        $<$<STREQUAL:$<TARGET_PROPERTY:CXX_RTTI>,ON>:CORE_HAS_CXX_RTTI>)

export(TARGETS Core_Settings
        NAMESPACE Core::
        FILE "${CMAKE_BINARY_DIR}/CoreSettingsExport.cmake")

install(TARGETS Core_Settings
        EXPORT CoreTargetsExportSet)