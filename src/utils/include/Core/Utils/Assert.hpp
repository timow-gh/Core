#ifndef CORE_ASSERT_H
#define CORE_ASSERT_H

#include <Core/Utils/Compiler.hpp>
#include <cstdint>
#include <iostream>
#include <string>

#ifdef CORE_HAS_CXX_EXCEPTIONS
#include <exception>
#endif

namespace Core
{
class Assert
#ifdef CORE_HAS_CXX_EXCEPTIONS
    : public std::exception
#endif
{
    const char* const m_message;
    const char* const m_function;
    const char* const m_file;
    const uint64_t m_line;

  public:
    explicit Assert(const char* message) CORE_NOEXCEPT
        : m_message(message)
        , m_function(nullptr)
        , m_file(nullptr)
        , m_line(0)
    {
    }

    Assert(const char* message,
           const char* function,
           const char* file,
           uint32_t line) CORE_NOEXCEPT
        : m_message(message)
        , m_function(function)
        , m_file(file)
        , m_line(line)
    {
    }

#ifdef CORE_HAS_CXX_EXCEPTIONS
    CORE_NODISCARD const char* what() const CORE_NOEXCEPT override
    {
        return m_message;
    }
#endif

    static void create(const char* message,
                       const char* function,
                       const char* file,
                       uint64_t line) CORE_NORETURN
    {
        std::cerr << "Post condition error: '" + std::string(message) << "',\n";
        std::cerr << "File: " + std::string(file) << ",\n";
        std::cerr << "Function:" + std::string(function) << ",\n";
        std::cerr << "Line: " + std::to_string(line) << std::endl;

#ifdef CORE_HAS_CXX_EXCEPTIONS
        throw Assert(message, function, file, line);
#endif
        std::abort();
    }

    CORE_NODISCARD const char* getMessage() const CORE_NOEXCEPT
    {
        return m_message;
    }
    CORE_NODISCARD const char* getFunction() const CORE_NOEXCEPT
    {
        return m_function;
    }
    CORE_NODISCARD const char* getFile() const CORE_NOEXCEPT { return m_file; }
    CORE_NODISCARD uint64_t getLine() const CORE_NOEXCEPT { return m_line; }
};

class PostConditionAssert
    : public Assert
{
  public:
    using Assert::Assert;
};

class PreConditionAssert
    : public Assert
{
  public:
    using Assert::Assert;
};

#ifndef NDEBUG
#define FILE_NAME(F) (F)
#else
#define FILE_NAME(F) ""
#endif

#define CORE_PRECONDITION_ASSERT_MESSAGE(message)                              \
    ::Core::PreConditionAssert::create(message,                                \
                                       __PRETTY_FUNCTION__,                    \
                                       FILE_NAME(__FILE__),                    \
                                       __LINE__)

#define CREATE_POSTCONDITION_ASSERT_MESSAGE(message)                           \
    ::Core::PostConditionAssert::create(message,                               \
                                        __PRETTY_FUNCTION__,                   \
                                        FILE_NAME(__FILE__),                   \
                                        __LINE__)

#define CORE_PRECONDITION_ASSERT(condition, message)                           \
    (!CORE_LIKELY(condition) ? CORE_PRECONDITION_ASSERT_MESSAGE(message)       \
                             : static_cast<void>(0))

#define CORE_POSTCONDITION_ASSERT(condition, message)                          \
    (!CORE_LIKELY(condition) ? CREATE_POSTCONDITION_ASSERT_MESSAGE(message)    \
                             : static_cast<void>(0))

#ifdef NDEBUG
#define CORE_PRECONDITION_DEBUG_ASSERT(condition, message)
#else
#define CORE_PRECONDITION_DEBUG_ASSERT(condition, message)                     \
    CORE_PRECONDITION_ASSERT(condition, message)
#endif

#ifdef NDEBUG
#define CORE_POSTCONDITION_DEBUG_ASSERT(condition, message)
#else
#define CORE_POSTCONDITION_DEBUG_ASSERT(condition, message)                    \
    CORE_POSTCONDITION_ASSERT(condition, message)
#endif
} // namespace Core

#endif // CORE_ASSERT_H
