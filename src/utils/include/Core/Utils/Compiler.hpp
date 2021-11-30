#ifndef CORE_COMPILER_HPP
#define CORE_COMPILER_HPP

#ifndef __has_attribute
#define __has_attribute(x) 0
#endif

#ifndef __has_feature
#define __has_feature(x) 0
#endif

#ifndef __has_builtin
#define __has_builtin(x) 0
#endif

#if __has_attribute(noreturn)
#    define CORE_NORETURN __attribute__((noreturn))
#else
#    define CORE_NORETURN
#endif

#if __has_attribute(deprecated)
#define CORE_DEPRECATED [[deprecated]]
#else
#define CORE_DEPRECATED
#endif

#if __has_attribute(packed)
#define CORE_PACKED __attribute__((packed))
#else
#define CORE_PACKED
#endif

#if __has_builtin(__builtin_expect)
#ifdef __cplusplus
#define CORE_LIKELY(exp) (__builtin_expect(!!(exp), true))
#define CORE_UNLIKELY(exp) (__builtin_expect(!!(exp), false))
#else
#define CORE_LIKELY(exp) (__builtin_expect(!!(exp), 1))
#define CORE_UNLIKELY(exp) (__builtin_expect(!!(exp), 0))
#endif
#else
#define CORE_LIKELY(exp) (!!(exp))
#define CORE_UNLIKELY(exp) (!!(exp))
#endif

#if __has_builtin(__builtin_prefetch)
#define CORE_PREFETCH(exp) (__builtin_prefetch(exp))
#else
#define CORE_PREFETCH(exp)
#endif

#if __has_attribute(always_inline)
#define CORE_ALWAYS_INLINE __attribute__((always_inline))
#else
#define CORE_ALWAYS_INLINE
#endif

#if __has_attribute(maybe_unused)
#define CORE_UNUSED [[maybe_unused]]
#define CORE_UNUSED_IN_RELEASE [[maybe_unused]]
#elif __has_attribute(unused)
#define CORE_UNUSED __attribute__((unused))
#define CORE_UNUSED_IN_RELEASE __attribute__((unused))
#else
#define CORE_UNUSED
#define CORE_UNUSED_IN_RELEASE
#endif

#if defined(_MSC_VER) && _MSC_VER >= 1900
#define CORE_RESTRICT __restrict
#elif (defined(__clang__) || defined(__GNUC__))
#define CORE_RESTRICT __restrict__
#else
#define CORE_RESTRICT
#endif

#ifndef NODISCARD
#define NODISCARD [[nodiscard]]
#else
#define NODISCARD
#endif

#ifndef NOEXCEPT
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

#if defined(_MSC_VER) && !defined(__PRETTY_FUNCTION__)
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

#endif // CORE_COMPILER_HPP
