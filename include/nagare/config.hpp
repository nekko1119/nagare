#ifndef NAGARE_CONFIG_HPP
#define NAGARE_CONFIG_HPP

#if defined(_MSC_VER)
#   if _MSC_FULL_VER < 191125506
#       define NAGARE_NO_CXX14_CONSTEXPR
#   endif
#elif defined(__GNUC__)
#   if !defined(__cpp_constexpr) || (__cpp_constexpr < 201304)
#       define NAGARE_NO_CXX14_CONSTEXPR
#   endif
#elif defined(__clang__)
#   if !__has_feature(cxx_relaxed_constexpr)
#       define NAGARE_NO_CXX14_CONSTEXPR
#   endif
#endif

#if defined(NAGARE_NO_CXX14_CONSTEXPR)
#   define NAGARE_CXX14_CONSTEXPR
#else
#   define NAGARE_CXX14_CONSTEXPR constexpr
#endif

#endif
