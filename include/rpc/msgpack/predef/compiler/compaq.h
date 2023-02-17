/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_COMPILER_COMPAQ_H
#define MSGPACK_PREDEF_COMPILER_COMPAQ_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_COMP_DEC`

http://www.openvms.compaq.com/openvms/brochures/deccplus/[Compaq C/{CPP}] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__DECCXX+` | {predef_detection}
| `+__DECC+` | {predef_detection}

| `+__DECCXX_VER+` | V.R.P
| `+__DECC_VER+` | V.R.P
|===
*/ // end::reference[]

#define MSGPACK_COMP_DEC MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__DECC) || defined(__DECCXX)
#   if !defined(MSGPACK_COMP_DEC_DETECTION) && defined(__DECCXX_VER)
#       define MSGPACK_COMP_DEC_DETECTION MSGPACK_PREDEF_MAKE_10_VVRR0PP00(__DECCXX_VER)
#   endif
#   if !defined(MSGPACK_COMP_DEC_DETECTION) && defined(__DECC_VER)
#       define MSGPACK_COMP_DEC_DETECTION MSGPACK_PREDEF_MAKE_10_VVRR0PP00(__DECC_VER)
#   endif
#   if !defined(MSGPACK_COMP_DEC_DETECTION)
#       define MSGPACK_COMP_DEC_DETECTION MSGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef MSGPACK_COMP_DEC_DETECTION
#   if defined(MSGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define MSGPACK_COMP_DEC_EMULATED MSGPACK_COMP_DEC_DETECTION
#   else
#       undef MSGPACK_COMP_DEC
#       define MSGPACK_COMP_DEC MSGPACK_COMP_DEC_DETECTION
#   endif
#   define MSGPACK_COMP_DEC_AVAILABLE
#   include <rpc/msgpack/predef/detail/comp_detected.h>
#endif

#define MSGPACK_COMP_DEC_NAME "Compaq C/C++"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_COMP_DEC,MSGPACK_COMP_DEC_NAME)

#ifdef MSGPACK_COMP_DEC_EMULATED
#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_COMP_DEC_EMULATED,MSGPACK_COMP_DEC_NAME)
#endif
