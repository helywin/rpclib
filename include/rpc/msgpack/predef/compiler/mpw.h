/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_COMPILER_MPW_H
#define MSGPACK_PREDEF_COMPILER_MPW_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_COMP_MPW`

http://en.wikipedia.org/wiki/Macintosh_Programmer%27s_Workshop[MPW {CPP}] compiler.
Version number available as major, and minor.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__MRC__+` | {predef_detection}
| `MPW_C` | {predef_detection}
| `MPW_CPLUS` | {predef_detection}

| `+__MRC__+` | V.R.0
|===
*/ // end::reference[]

#define MSGPACK_COMP_MPW MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
#   if !defined(MSGPACK_COMP_MPW_DETECTION) && defined(__MRC__)
#       define MSGPACK_COMP_MPW_DETECTION MSGPACK_PREDEF_MAKE_0X_VVRR(__MRC__)
#   endif
#   if !defined(MSGPACK_COMP_MPW_DETECTION)
#       define MSGPACK_COMP_MPW_DETECTION MSGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef MSGPACK_COMP_MPW_DETECTION
#   if defined(MSGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define MSGPACK_COMP_MPW_EMULATED MSGPACK_COMP_MPW_DETECTION
#   else
#       undef MSGPACK_COMP_MPW
#       define MSGPACK_COMP_MPW MSGPACK_COMP_MPW_DETECTION
#   endif
#   define MSGPACK_COMP_MPW_AVAILABLE
#   include <rpc/msgpack/predef/detail/comp_detected.h>
#endif

#define MSGPACK_COMP_MPW_NAME "MPW C++"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_COMP_MPW,MSGPACK_COMP_MPW_NAME)

#ifdef MSGPACK_COMP_MPW_EMULATED
#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_COMP_MPW_EMULATED,MSGPACK_COMP_MPW_NAME)
#endif
