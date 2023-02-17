/*
Copyright Zhang Na 2022
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_ARCHITECTURE_LOONGARCH_H
#define MSGPACK_PREDEF_ARCHITECTURE_LOONGARCH_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_ARCH_LOONGARCH`

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__loongarch__+` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_ARCH_LOONGARCH MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__loongarch__)
#   undef MSGPACK_ARCH_LOONGARCH
#   define MSGPACK_ARCH_LOONGARCH MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if MSGPACK_ARCH_LOONGARCH
#   define MSGPACK_ARCH_LOONGARCH_AVAILABLE
#endif

#define MSGPACK_ARCH_LOONGARCH_NAME "LoongArch"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_ARCH_LOONGARCH,MSGPACK_ARCH_LOONGARCH_NAME)
