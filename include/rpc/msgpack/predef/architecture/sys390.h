/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_ARCHITECTURE_SYS390_H
#define MSGPACK_PREDEF_ARCHITECTURE_SYS390_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_ARCH_SYS390`

http://en.wikipedia.org/wiki/System/390[System/390] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__s390__+` | {predef_detection}
| `+__s390x__+` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_ARCH_SYS390 MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__s390__) || defined(__s390x__)
#   undef MSGPACK_ARCH_SYS390
#   define MSGPACK_ARCH_SYS390 MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if MSGPACK_ARCH_SYS390
#   define MSGPACK_ARCH_SYS390_AVAILABLE
#endif

#if MSGPACK_ARCH_SYS390
#   undef MSGPACK_ARCH_WORD_BITS_32
#   define MSGPACK_ARCH_WORD_BITS_32 MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#define MSGPACK_ARCH_SYS390_NAME "System/390"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_ARCH_SYS390,MSGPACK_ARCH_SYS390_NAME)
