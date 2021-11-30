#ifndef CORE_ASSERT_H
#define CORE_ASSERT_H

#include <Core/Utils/Compiler.hpp>
#include <exception>

namespace Core
{
class Assert
    : public std::exception
{
    const char* const m_message;
    const char* const m_function;
    const char* const m_file;
    const uint32_t m_line;

  public:
    explicit Assert(const char* message) NOEXCEPT
        : m_message(message)
        , m_function(nullptr)
        , m_file(nullptr)
        , m_line(0)
    {
    }

    Assert(const char* message,
           const char* function,
           const char* file,
           uint32_t line) NOEXCEPT
        : m_message(message)
        , m_function(function)
        , m_file(file)
        , m_line(line)
    {
    }

    const char* what() const NOEXCEPT override { return m_message; }

    static void create(const char* message,
                       const char* function,
                       const char* file,
                       uint32_t line) CORE_NORETURN
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

    NODISCARD const char* getMessage() const NOEXCEPT { return what(); }
    NODISCARD const char* getFunction() const NOEXCEPT { return m_function; }
    NODISCARD const char* getFile() const NOEXCEPT { return m_file; }
    NODISCARD uint32_t getLine() const NOEXCEPT { return m_line; }
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

#define PRECONDITION_ASSERT(message)                                           \
    ::Core::PreConditionAssert::create(message,                                \
                                       __PRETTY_FUNCTION__,                    \
                                       FILE_NAME(__FILE__),                    \
                                       __LINE__)

#define POSTCONDITION_ASSERT(message)                                          \
    ::Core::PostConditionAssert::create(message,                               \
                                        __PRETTY_FUNCTION__,                   \
                                        FILE_NAME(__FILE__),                   \
                                        __LINE__)

#define CORE_ASSERT_PRECONDITION(condition, message)                           \
    (!CORE_LIKELY(condition) ? PRECONDITION_ASSERT(message)                    \
                             : static_cast<void>(0))

#define CORE_ASSERT_POSTCONDITION(condition, message)                          \
    (!CORE_LIKELY(condition) ? POSTCONDITION_ASSERT(message)                   \
                             : static_cast<void>(0))

#ifdef NDEBUG
#define CORE_DEBUG_ASSERT_PRECONDITION(condition, message)
#else
#define CORE_DEBUG_ASSERT_PRECONDITION(condition, message)                     \
    (!CORE_LIKELY(condition) ? POSTCONDITION_ASSERT(message)                   \
                             : static_cast<void>(0))
#endif

#ifdef NDEBUG
#define CORE_DEBUG_ASSERT_POSTCONDITION(condition, message)
#else
#define CORE_DEBUG_ASSERT_POSTCONDITION(condition, message)                    \
    (!CORE_LIKELY(condition) ? POSTCONDITION_ASSERT(message)                   \
                             : static_cast<void>(0))
#endif
} // namespace Core

#endif // CORE_ASSERT_H
