/*
Copyright Benjamin Worpitz 2018
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_ARCHITECTURE_PTX_H
#define MSGPACK_PREDEF_ARCHITECTURE_PTX_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_ARCH_PTX`

https://en.wikipedia.org/wiki/Parallel_Thread_Execution[PTX] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__CUDA_ARCH__+` | {predef_detection}

| `+__CUDA_ARCH__+` | V.R.0
|===
*/ // end::reference[]

#define MSGPACK_ARCH_PTX MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__CUDA_ARCH__)
#   undef MSGPACK_ARCH_PTX
#   define MSGPACK_ARCH_PTX MSGPACK_PREDEF_MAKE_10_VR0(__CUDA_ARCH__)
#endif

#if MSGPACK_ARCH_PTX
#   define MSGPACK_ARCH_PTX_AVAILABLE
#endif

#if MSGPACK_ARCH_PTX
#   undef MSGPACK_ARCH_WORD_BITS_64
#   define MSGPACK_ARCH_WORD_BITS_64 MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#define MSGPACK_ARCH_PTX_NAME "PTX"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_ARCH_PTX,MSGPACK_ARCH_PTX_NAME)
