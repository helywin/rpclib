/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_COMPILER_IAR_H
#define MSGPACK_PREDEF_COMPILER_IAR_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_COMP_IAR`

IAR C/{CPP} compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__IAR_SYSTEMS_ICC__+` | {predef_detection}

| `+__VER__+` | V.R.P
|===
*/ // end::reference[]

#define MSGPACK_COMP_IAR MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__IAR_SYSTEMS_ICC__)
#   define MSGPACK_COMP_IAR_DETECTION MSGPACK_PREDEF_MAKE_10_VVRR(__VER__)
#endif

#ifdef MSGPACK_COMP_IAR_DETECTION
#   if defined(MSGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define MSGPACK_COMP_IAR_EMULATED MSGPACK_COMP_IAR_DETECTION
#   else
#       undef MSGPACK_COMP_IAR
#       define MSGPACK_COMP_IAR MSGPACK_COMP_IAR_DETECTION
#   endif
#   define MSGPACK_COMP_IAR_AVAILABLE
#   include <rpc/msgpack/predef/detail/comp_detected.h>
#endif

#define MSGPACK_COMP_IAR_NAME "IAR C/C++"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_COMP_IAR,MSGPACK_COMP_IAR_NAME)

#ifdef MSGPACK_COMP_IAR_EMULATED
#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_COMP_IAR_EMULATED,MSGPACK_COMP_IAR_NAME)
#endif
