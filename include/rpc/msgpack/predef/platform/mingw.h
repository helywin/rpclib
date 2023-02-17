/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_PLAT_MINGW_H
#define MSGPACK_PREDEF_PLAT_MINGW_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_PLAT_MINGW`

http://en.wikipedia.org/wiki/MinGW[MinGW] platform, either variety.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__MINGW32__+` | {predef_detection}
| `+__MINGW64__+` | {predef_detection}

| `+__MINGW64_VERSION_MAJOR+`, `+__MINGW64_VERSION_MINOR+` | V.R.0
| `+__MINGW32_VERSION_MAJOR+`, `+__MINGW32_VERSION_MINOR+` | V.R.0
|===
*/ // end::reference[]

#define MSGPACK_PLAT_MINGW MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MINGW32__) || defined(__MINGW64__)
#   include <_mingw.h>
#   if !defined(MSGPACK_PLAT_MINGW_DETECTION) && (defined(__MINGW64_VERSION_MAJOR) && defined(__MINGW64_VERSION_MINOR))
#       define MSGPACK_PLAT_MINGW_DETECTION \
            MSGPACK_VERSION_NUMBER(__MINGW64_VERSION_MAJOR,__MINGW64_VERSION_MINOR,0)
#   endif
#   if !defined(MSGPACK_PLAT_MINGW_DETECTION) && (defined(__MINGW32_VERSION_MAJOR) && defined(__MINGW32_VERSION_MINOR))
#       define MSGPACK_PLAT_MINGW_DETECTION \
            MSGPACK_VERSION_NUMBER(__MINGW32_MAJOR_VERSION,__MINGW32_MINOR_VERSION,0)
#   endif
#   if !defined(MSGPACK_PLAT_MINGW_DETECTION)
#       define MSGPACK_PLAT_MINGW_DETECTION MSGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef MSGPACK_PLAT_MINGW_DETECTION
#   define MSGPACK_PLAT_MINGW_AVAILABLE
#   if defined(MSGPACK_PREDEF_DETAIL_PLAT_DETECTED)
#       define MSGPACK_PLAT_MINGW_EMULATED MSGPACK_PLAT_MINGW_DETECTION
#   else
#       undef MSGPACK_PLAT_MINGW
#       define MSGPACK_PLAT_MINGW MSGPACK_PLAT_MINGW_DETECTION
#   endif
#   include <rpc/msgpack/predef/detail/platform_detected.h>
#endif

#define MSGPACK_PLAT_MINGW_NAME "MinGW (any variety)"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_PLAT_MINGW,MSGPACK_PLAT_MINGW_NAME)

#ifdef MSGPACK_PLAT_MINGW_EMULATED
#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_PLAT_MINGW_EMULATED,MSGPACK_PLAT_MINGW_NAME)
#endif
