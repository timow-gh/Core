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

target_compile_features(Core_Settings INTERFACE cxx_std_17)

target_compile_definitions(Core_Settings INTERFACE
        $<$<STREQUAL:$<TARGET_PROPERTY:CXX_EXCEPTIONS>,ON>:CORE_HAS_CXX_EXCEPTIONS>
        $<$<STREQUAL:$<TARGET_PROPERTY:CXX_RTTI>,ON>:CORE_HAS_CXX_RTTI>)

#[[
    Clang and gcc compile and link options based on:
    https://github.com/davidstone/cmake_Core_Settings/blob/main/CMakeLists.txt
]]

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR
        "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    find_program(CORE_LDD_PROGRAM NAMES "lld")
    if (NOT CORE_LDD_PROGRAM)
        message(WARNING "Linker lld not found, using default linker.")
    else ()
        message(STATUS "Found linker lld.")
        target_link_options(Core_Settings INTERFACE
                "-fuse-ld=lld"
                )
    endif ()
    target_link_options(Core_Settings INTERFACE
            "-Wl,--fatal-warnings"
            )
endif ()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message(STATUS "Compiler Settings ${CMAKE_CXX_COMPILER_ID}")
    if (MSVC)
        # Sanitizers currently do not work very well on Windows
        set(use_sanitizers OFF)
        target_compile_options(Core_Settings INTERFACE
                "/MP"
                )
        target_link_options(Core_Settings INTERFACE
                "/WX"
                )
    endif ()

    target_compile_options(Core_Settings INTERFACE
            "-Weverything"
            "-Wno-global-constructors"
            "-Werror"
            # There are too many warnings in third party libraries.
            # "-Wconversion"
            # google tests return sentinels are marked unused but are used
            "-Wno-used-but-marked-unused"
            "-Wno-covered-switch-default"
            # Don't need compatibility with older standards
            "-Wno-c++98-compat"
            # Don't need compatibility with older standards
            "-Wno-c++98-compat-pedantic"
            # Standard library modules are not quite supported yet, it seems
            "-Wno-auto-import"
            # This warning tries to enforce a particular coding standard
            "-Wno-ctad-maybe-unsupported"
            # Complains about comments like "//<N3757>" referring to an ISO paper number
            "-Wno-documentation"
            # There are too many cases of correct exact comparisons
            "-Wno-float-equal"
            # https://bugs.llvm.org/show_bug.cgi?id=49665
            "-Wno-for-loop-analysis"
            # -Wmissing-braces wants two sets of braces for std::array
            "-Wno-missing-braces"
            "-Wno-newline-eof"
            # https://bugs.llvm.org/show_bug.cgi?id=22442#c5
            "-Wno-padded"
            # Warns about intentional copies in range-based for loops
            "-Wno-range-loop-analysis"
            # -Wswitch-enum warns even if you have default
            "-Wno-switch-enum"
            # https://llvm.org/bugs/show_bug.cgi?id=25084
            "-Wno-unneeded-member-function"
            # https://llvm.org/bugs/show_bug.cgi?id=25084
            "-Wno-unused-member-function"
            # https://llvm.org/bugs/show_bug.cgi?id=25084
            "-Wno-unused-function"
            # https://llvm.org/bugs/show_bug.cgi?id=25084
            "-Wno-unused-template"
            # https://bugs.llvm.org/show_bug.cgi?id=44325
            "-Wno-zero-as-null-pointer-constant"
            )
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message(STATUS "Compiler Settings ${CMAKE_CXX_COMPILER_ID}")
    target_compile_options(Core_Settings INTERFACE
            "-Wall"
            "-Wno-global-constructors"
            "-Werror"
            "-Wextra"
            "-Wpedantic"
            # Do not care about ABI differences
            # "-Wabi"
            "-Wcast-align"
            "-Wcast-qual"
            # https://gcc.gnu.org/bugzilla/show_bug.cgi?id=39170
            # There are too many warnings in third party libraries.
            # "-Wconversion"
            # A reasonable code pattern is to use a private member function with
            # `if constexpr (requires { expr; }) { static_assert(expr); } }`
            # This might be the only member function of a class if it's a trait
            # class. Such a pattern triggers this warning.
            "-Wno-ctor-dtor-privacy"
            "-Wdisabled-optimization"
            "-Wdouble-promotion"
            # -Weffc++ includes a warning if all data members are not explicitly
            # initialized in the initializer list. I intentionally do not do this in
            # many cases. This would be more useful as a collection of warnings
            # like -Wall instead of a single warning on its own.
            # "-Weffc++"
            # There are too many cases of correct exact comparisons
            "-Wno-float-equal"
            "-Wformat=2"
            # Warns for `static_cast<decltype(x)>`
            "-Wno-ignored-qualifiers"
            "-Winit-self"
            "-Winvalid-pch"
            # -Wlogical-op warns for expressions that happen to be equal in a
            # template instantiation
            # "-Wlogical-op"
            "-Wmissing-declarations"
            # -Wmissing-format-attribute is not used because I do not use GNU
            # extensions. Same for -Wsuggest-attribute and several others.
            # "-Wmissing-include-dirs"
            #"-Wnoexcept"
            "-Wno-non-template-friend"
            "-Wold-style-cast"
            "-Woverloaded-virtual"
            # https://gcc.gnu.org/bugzilla/show_bug.cgi?id=52981#c5
            "-Wno-padded"
            "-Wredundant-decls"
            "-Wshadow"
            # Warns for constant expressions that are guaranteed to be safe
            "-Wno-sign-conversion"
            "-Wsign-promo"
            # -Wsuggest-final-methods and -Wsuggest-final-types is a linker warning,
            # so it is not possible to disable it for boost and other third-party
            # libraries by saying they are system headers.
            # "-Wsuggest-final-methods"
            # "-Wsuggest-final-types"
            "-Wstrict-null-sentinel"
            # -Wstrict-overflow=2 warns about comparing two pointers
            "-Wstrict-overflow=1"
            # -Wswitch-enum warns even if all enumerators are handled
            "-Wno-switch-default"
            # -Wswitch-enum warns even if there is a default
            "-Wno-switch-enum"
            "-Wtrampolines"
            "-Wundef"
            # -Wunsafe-loop-optimizations causes too many spurious warnings. It may
            # be useful to apply this one periodically and manually verify the
            # results. It generated this warning in my code when I looped over all
            # elements in a vector to apply a set of functions to them (using the
            # range-based for loop). It is also warning for the constructor of a
            # const array of const std::string where there is no loop in user code.
            # "-Wunsafe-loop-optimizations"
            # -Wunused-but-set-parameter does not properly account for
            # `if constexpr` branches.
            "-Wno-unused-but-set-parameter"
            # -Wunused-but-set-variable does not properly account for
            # `if constexpr` branches.
            "-Wno-unused-but-set-variable"
            # Incompatible with operator?: macro
            # "-Wuseless-cast"
            "-Wvector-operation-performance"
            # Warns on explicit template instantiations due to some bug
            "-Wno-unused-parameter"
            # -Wzero-as-null-pointer-constant does not work with the `operator<=>`
            # emulation
            # "-Wzero-as-null-pointer-constant"
            )
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    message(STATUS "Compiler Settings ${CMAKE_CXX_COMPILER_ID}")
    # Purge unconditional use of these flags
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
    # Add flags based selected by the properties
    target_compile_options(Core_Settings INTERFACE
            $<$<STREQUAL:$<TARGET_PROPERTY:CXX_EXCEPTIONS>,ON>:/EHsc>
            $<$<STREQUAL:$<TARGET_PROPERTY:CXX_RTTI>,OFF>:/GR->)
endif ()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"
        OR
        "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(Core_Settings INTERFACE
            $<$<COMPILE_LANGUAGE:CXX>:$<$<STREQUAL:$<TARGET_PROPERTY:CXX_EXCEPTIONS>,ON>:-fexceptions>>
            $<$<COMPILE_LANGUAGE:CXX>:$<$<STREQUAL:$<TARGET_PROPERTY:CXX_RTTI>,ON>:-frtti>>
            $<$<COMPILE_LANGUAGE:CXX>:$<$<STREQUAL:$<TARGET_PROPERTY:CXX_EXCEPTIONS>,OFF>:-fno-exceptions>>
            $<$<COMPILE_LANGUAGE:CXX>:$<$<STREQUAL:$<TARGET_PROPERTY:CXX_RTTI>,OFF>:-fno-rtti>>
            )
endif ()

export(TARGETS Core_Settings
        NAMESPACE Core::
        FILE "${CMAKE_BINARY_DIR}/CoreSettingsExport.cmake")

install(TARGETS Core_Settings
        EXPORT CoreTargetsExportSet)