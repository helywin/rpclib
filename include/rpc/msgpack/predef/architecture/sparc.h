/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_ARCHITECTURE_SPARC_H
#define MSGPACK_PREDEF_ARCHITECTURE_SPARC_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_ARCH_SPARC`

http://en.wikipedia.org/wiki/SPARC[SPARC] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__sparc__+` | {predef_detection}
| `+__sparc+` | {predef_detection}

| `+__sparcv9+` | 9.0.0
| `+__sparc_v9__+` | 9.0.0
| `+__sparcv8+` | 8.0.0
| `+__sparc_v8__+` | 8.0.0
|===
*/ // end::reference[]

#define MSGPACK_ARCH_SPARC MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__sparc__) || defined(__sparc)
#   undef MSGPACK_ARCH_SPARC
#   if !defined(MSGPACK_ARCH_SPARC) && (defined(__sparcv9) || defined(__sparc_v9__))
#       define MSGPACK_ARCH_SPARC MSGPACK_VERSION_NUMBER(9,0,0)
#   endif
#   if !defined(MSGPACK_ARCH_SPARC) && (defined(__sparcv8) || defined(__sparc_v8__))
#       define MSGPACK_ARCH_SPARC MSGPACK_VERSION_NUMBER(8,0,0)
#   endif
#   if !defined(MSGPACK_ARCH_SPARC)
#       define MSGPACK_ARCH_SPARC MSGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if MSGPACK_ARCH_SPARC
#   define MSGPACK_ARCH_SPARC_AVAILABLE
#endif

#if MSGPACK_ARCH_SPARC
#   if MSGPACK_ARCH_SPARC >= MSGPACK_VERSION_NUMBER(9,0,0)
#       undef MSGPACK_ARCH_WORD_BITS_64
#       define MSGPACK_ARCH_WORD_BITS_64 MSGPACK_VERSION_NUMBER_AVAILABLE
#   else
#       undef MSGPACK_ARCH_WORD_BITS_32
#       define MSGPACK_ARCH_WORD_BITS_32 MSGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#define MSGPACK_ARCH_SPARC_NAME "SPARC"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_ARCH_SPARC,MSGPACK_ARCH_SPARC_NAME)
