/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_COMPILER_DIAB_H
#define MSGPACK_PREDEF_COMPILER_DIAB_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_COMP_DIAB`

http://www.windriver.com/products/development_suite/wind_river_compiler/[Diab C/{CPP}] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__DCC__+` | {predef_detection}

| `+__VERSION_NUMBER__+` | V.R.P
|===
*/ // end::reference[]

#define MSGPACK_COMP_DIAB MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__DCC__)
#   define MSGPACK_COMP_DIAB_DETECTION MSGPACK_PREDEF_MAKE_10_VRPP(__VERSION_NUMBER__)
#endif

#ifdef MSGPACK_COMP_DIAB_DETECTION
#   if defined(MSGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define MSGPACK_COMP_DIAB_EMULATED MSGPACK_COMP_DIAB_DETECTION
#   else
#       undef MSGPACK_COMP_DIAB
#       define MSGPACK_COMP_DIAB MSGPACK_COMP_DIAB_DETECTION
#   endif
#   define MSGPACK_COMP_DIAB_AVAILABLE
#   include <rpc/msgpack/predef/detail/comp_detected.h>
#endif

#define MSGPACK_COMP_DIAB_NAME "Diab C/C++"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_COMP_DIAB,MSGPACK_COMP_DIAB_NAME)

#ifdef MSGPACK_COMP_DIAB_EMULATED
#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_COMP_DIAB_EMULATED,MSGPACK_COMP_DIAB_NAME)
#endif
