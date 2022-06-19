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

template <typename DerivedAssert>
class Assert
#ifdef CORE_HAS_CXX_EXCEPTIONS
    : public std::exception
#endif
{
    const char* const m_message;
    const char* const m_function;
    const char* const m_file;
    const uint64_t m_line;

  protected:
    CORE_NODISCARD std::string getMessagePrefix() const CORE_NOEXCEPT
    {
        return static_cast<const DerivedAssert*>(this)->getMessagePrefixImpl();
    }

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
           std::uint64_t line) CORE_NOEXCEPT
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
                       std::uint64_t line) CORE_NORETURN
    {
        Assert assertion = Assert(message, function, file, line);
        std::cerr << assertion.composeLogMessage();
#ifdef CORE_HAS_CXX_EXCEPTIONS
        throw assertion;
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
    CORE_NODISCARD const char* getFile() const CORE_NOEXCEPT
    {
        return m_file;
    }
    CORE_NODISCARD uint64_t getLine() const CORE_NOEXCEPT
    {
        return m_line;
    }

  private:
    CORE_NODISCARD std::string composeLogMessage() const CORE_NOEXCEPT
    {
        std::string result;
        result = std::string(getMessagePrefix()) + " error : '" +
                 std::string(m_message) + "',\n";
        result += "File: " + std::string(m_file) + ",\n";
        result += "Function:" + std::string(m_function) + ",\n";
        result += "Line: " + std::to_string(m_line) + "\n";
        return result;
    }
};

class PostConditionAssert : public Assert<PostConditionAssert> {
  public:
    using Assert::Assert;

    CORE_NODISCARD std::string getMessagePrefixImpl() const CORE_NOEXCEPT
    {
        return std::string{"Postcondition"};
    }
};

class PreConditionAssert : public Assert<PreConditionAssert> {
  public:
    using Assert::Assert;

    CORE_NODISCARD std::string getMessagePrefixImpl() const CORE_NOEXCEPT
    {
        return std::string{"Precondition"};
    }
};
} // namespace Core

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

#endif // CORE_ASSERT_H
