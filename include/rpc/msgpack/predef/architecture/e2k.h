/*
Copyright Konstantin Ivlev 2021
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_ARCHITECTURE_E2K_H
#define MSGPACK_PREDEF_ARCHITECTURE_E2K_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_ARCH_E2K`

https://en.wikipedia.org/wiki/Elbrus_2000[E2K] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__e2k__+` | {predef_detection}

| `+__e2k__+` | V.0.0
|===
*/ // end::reference[]

#define MSGPACK_ARCH_E2K MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__e2k__)
#   undef MSGPACK_ARCH_E2K
#   if !defined(MSGPACK_ARCH_E2K) && defined(__iset__)
#       define MSGPACK_ARCH_E2K MSGPACK_VERSION_NUMBER(__iset__,0,0)
#   endif
#   if !defined(MSGPACK_ARCH_E2K)
#       define MSGPACK_ARCH_E2K MSGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if MSGPACK_ARCH_E2K
#   define MSGPACK_ARCH_E2K_AVAILABLE
#endif

#if MSGPACK_ARCH_E2K
#   define MSGPACK_ARCH_WORD_BITS_64 MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#define MSGPACK_ARCH_E2K_NAME "E2K"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_ARCH_E2K,MSGPACK_ARCH_E2K_NAME)
