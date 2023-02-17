/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_ARCHITECTURE_Z_H
#define MSGPACK_PREDEF_ARCHITECTURE_Z_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_ARCH_Z`

http://en.wikipedia.org/wiki/Z/Architecture[z/Architecture] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__SYSC_ZARCH__+` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_ARCH_Z MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__SYSC_ZARCH__)
#   undef MSGPACK_ARCH_Z
#   define MSGPACK_ARCH_Z MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if MSGPACK_ARCH_Z
#   define MSGPACK_ARCH_Z_AVAILABLE
#endif

#if MSGPACK_ARCH_Z
#   undef MSGPACK_ARCH_WORD_BITS_64
#   define MSGPACK_ARCH_WORD_BITS_64 MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#define MSGPACK_ARCH_Z_NAME "z/Architecture"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_ARCH_Z,MSGPACK_ARCH_Z_NAME)
