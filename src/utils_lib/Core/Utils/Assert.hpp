#ifndef CORE_INCLUDE_GUARD_ASSERT_H
#define CORE_INCLUDE_GUARD_ASSERT_H

#include <Core/Utils/Compiler.hpp>
#include <Core/Utils/Warnings.hpp>
DISABLE_ALL_WARNINGS
#include <debug_assert.hpp>
ENABLE_ALL_WARNINGS

namespace Core
{

#define DEFAULT_ASSERTION_LEVEL 1

struct global_debug_assertion
    : debug_assert::default_handler
    , debug_assert::set_level<DEFAULT_ASSERTION_LEVEL>
{
};

} // namespace Core

#ifdef NDEBUG
#define CORE_ASSERT(expr)
#define CORE_ASSERT_MSG(expr, message)
#else
#define CORE_ASSERT(expr) DEBUG_ASSERT(expr, ::Core::global_debug_assertion{})
#define CORE_ASSERT_MSG(expr, message) DEBUG_ASSERT(expr, ::Core::global_debug_assertion{}, message)
#endif

/*
 * Deprecated. The following macros are deprecated and are just aliases for the new ones.
 */

#define CORE_PRECONDITION_ASSERT(expr, message) DEBUG_ASSERT(expr, ::Core::global_debug_assertion{}, message)
#define CORE_POSTCONDITION_ASSERT(expr, message) DEBUG_ASSERT(expr, ::Core::global_debug_assertion{}, message)

#ifdef NDEBUG
#define CORE_PRECONDITION_DEBUG_ASSERT(expr, message)
#else
#define CORE_PRECONDITION_DEBUG_ASSERT(expr, message) CORE_PRECONDITION_ASSERT(expr, message)
#endif

#ifdef NDEBUG
#define CORE_POSTCONDITION_DEBUG_ASSERT(expr, message)
#else
#define CORE_POSTCONDITION_DEBUG_ASSERT(expr, message) CORE_POSTCONDITION_ASSERT(expr, message)
#endif

#endif // CORE_INCLUDE_GUARD_ASSERT_H
