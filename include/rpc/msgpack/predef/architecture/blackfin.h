/*
Copyright Rene Rivera 2013-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_ARCHITECTURE_BLACKFIN_H
#define MSGPACK_PREDEF_ARCHITECTURE_BLACKFIN_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_ARCH_BLACKFIN`

Blackfin Processors from Analog Devices.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__bfin__+` | {predef_detection}
| `+__BFIN__+` | {predef_detection}
| `bfin` | {predef_detection}
| `BFIN` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_ARCH_BLACKFIN MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__bfin__) || defined(__BFIN__) || \
    defined(bfin) || defined(BFIN)
#   undef MSGPACK_ARCH_BLACKFIN
#   define MSGPACK_ARCH_BLACKFIN MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if MSGPACK_ARCH_BLACKFIN
#   define MSGPACK_ARCH_BLACKFIN_AVAILABLE
#endif

#if MSGPACK_ARCH_BLACKFIN
#   undef MSGPACK_ARCH_WORD_BITS_16
#   define MSGPACK_ARCH_WORD_BITS_16 MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#define MSGPACK_ARCH_BLACKFIN_NAME "Blackfin"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_ARCH_BLACKFIN,MSGPACK_ARCH_BLACKFIN_NAME)
