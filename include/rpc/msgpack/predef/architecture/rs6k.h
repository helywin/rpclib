/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_ARCHITECTURE_RS6K_H
#define MSGPACK_PREDEF_ARCHITECTURE_RS6K_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_ARCH_RS6000`

http://en.wikipedia.org/wiki/RS/6000[RS/6000] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__THW_RS6000+` | {predef_detection}
| `+_IBMR2+` | {predef_detection}
| `+_POWER+` | {predef_detection}
| `+_ARCH_PWR+` | {predef_detection}
| `+_ARCH_PWR2+` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_ARCH_RS6000 MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__THW_RS6000) || defined(_IBMR2) || \
    defined(_POWER) || defined(_ARCH_PWR) || \
    defined(_ARCH_PWR2)
#   undef MSGPACK_ARCH_RS6000
#   define MSGPACK_ARCH_RS6000 MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if MSGPACK_ARCH_RS6000
#   define MSGPACK_ARCH_RS6000_AVAILABLE
#endif

#if MSGPACK_ARCH_RS6000
#   undef MSGPACK_ARCH_WORD_BITS_32
#   define MSGPACK_ARCH_WORD_BITS_32 MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#define MSGPACK_ARCH_RS6000_NAME "RS/6000"

#define MSGPACK_ARCH_PWR MSGPACK_ARCH_RS6000

#if MSGPACK_ARCH_PWR
#   define MSGPACK_ARCH_PWR_AVAILABLE
#endif

#if MSGPACK_ARCH_PWR
#   undef MSGPACK_ARCH_WORD_BITS_32
#   define MSGPACK_ARCH_WORD_BITS_32 MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#define MSGPACK_ARCH_PWR_NAME MSGPACK_ARCH_RS6000_NAME

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_ARCH_RS6000,MSGPACK_ARCH_RS6000_NAME)
