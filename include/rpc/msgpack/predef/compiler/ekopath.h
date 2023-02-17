/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_COMPILER_EKOPATH_H
#define MSGPACK_PREDEF_COMPILER_EKOPATH_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_COMP_PATH`

http://en.wikipedia.org/wiki/PathScale[EKOpath] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__PATHCC__+` | {predef_detection}

| `+__PATHCC__+`, `+__PATHCC_MINOR__+`, `+__PATHCC_PATCHLEVEL__+` | V.R.P
|===
*/ // end::reference[]

#define MSGPACK_COMP_PATH MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__PATHCC__)
#   define MSGPACK_COMP_PATH_DETECTION \
        MSGPACK_VERSION_NUMBER(__PATHCC__,__PATHCC_MINOR__,__PATHCC_PATCHLEVEL__)
#endif

#ifdef MSGPACK_COMP_PATH_DETECTION
#   if defined(MSGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define MSGPACK_COMP_PATH_EMULATED MSGPACK_COMP_PATH_DETECTION
#   else
#       undef MSGPACK_COMP_PATH
#       define MSGPACK_COMP_PATH MSGPACK_COMP_PATH_DETECTION
#   endif
#   define MSGPACK_COMP_PATH_AVAILABLE
#   include <rpc/msgpack/predef/detail/comp_detected.h>
#endif

#define MSGPACK_COMP_PATH_NAME "EKOpath"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_COMP_PATH,MSGPACK_COMP_PATH_NAME)

#ifdef MSGPACK_COMP_PATH_EMULATED
#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_COMP_PATH_EMULATED,MSGPACK_COMP_PATH_NAME)
#endif
