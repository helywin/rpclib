/*
Copyright Andreas Schwab 2019
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_ARCHITECTURE_RISCV_H
#define MSGPACK_PREDEF_ARCHITECTURE_RISCV_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_ARCH_RISCV`

http://en.wikipedia.org/wiki/RISC-V[RISC-V] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__riscv+` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_ARCH_RISCV MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__riscv)
#   undef MSGPACK_ARCH_RISCV
#   define MSGPACK_ARCH_RISCV MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if MSGPACK_ARCH_RISCV
#   define MSGPACK_ARCH_RISCV_AVAILABLE
#endif

#if MSGPACK_ARCH_RISCV
#   undef MSGPACK_ARCH_WORD_BITS_32
#   define MSGPACK_ARCH_WORD_BITS_32 MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#define MSGPACK_ARCH_RISCV_NAME "RISC-V"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_ARCH_RISCV,MSGPACK_ARCH_RISCV_NAME)
