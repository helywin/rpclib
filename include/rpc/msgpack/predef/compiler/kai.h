/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_COMPILER_KAI_H
#define MSGPACK_PREDEF_COMPILER_KAI_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_COMP_KCC`

Kai {CPP} compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__KCC+` | {predef_detection}

| `+__KCC_VERSION+` | V.R.P
|===
*/ // end::reference[]

#define MSGPACK_COMP_KCC MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__KCC)
#   define MSGPACK_COMP_KCC_DETECTION MSGPACK_PREDEF_MAKE_0X_VRPP(__KCC_VERSION)
#endif

#ifdef MSGPACK_COMP_KCC_DETECTION
#   if defined(MSGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define MSGPACK_COMP_KCC_EMULATED MSGPACK_COMP_KCC_DETECTION
#   else
#       undef MSGPACK_COMP_KCC
#       define MSGPACK_COMP_KCC MSGPACK_COMP_KCC_DETECTION
#   endif
#   define MSGPACK_COMP_KCC_AVAILABLE
#   include <rpc/msgpack/predef/detail/comp_detected.h>
#endif

#define MSGPACK_COMP_KCC_NAME "Kai C++"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_COMP_KCC,MSGPACK_COMP_KCC_NAME)

#ifdef MSGPACK_COMP_KCC_EMULATED
#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_COMP_KCC_EMULATED,MSGPACK_COMP_KCC_NAME)
#endif
