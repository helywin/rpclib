/*
 * Copyright (C) 2017 James E. King III
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef MSGPACK_PREDEF_LIBRARY_C_CLOUDABI_H
#define MSGPACK_PREDEF_LIBRARY_C_CLOUDABI_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

#include <rpc/msgpack/predef/library/c/_prefix.h>

#if defined(__CloudABI__)
#include <stddef.h>
#endif

/* tag::reference[]
= `MSGPACK_LIB_C_CLOUDABI`

https://github.com/NuxiNL/cloudlibc[cloudlibc] - CloudABI's standard C library.
Version number available as major, and minor.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__cloudlibc__+` | {predef_detection}

| `+__cloudlibc_major__+`, `+__cloudlibc_minor__+` | V.R.0
|===
*/ // end::reference[]

#define MSGPACK_LIB_C_CLOUDABI MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__cloudlibc__)
#   undef MSGPACK_LIB_C_CLOUDABI
#   define MSGPACK_LIB_C_CLOUDABI \
            MSGPACK_VERSION_NUMBER(__cloudlibc_major__,__cloudlibc_minor__,0)
#endif

#if MSGPACK_LIB_C_CLOUDABI
#   define MSGPACK_LIB_C_CLOUDABI_AVAILABLE
#endif

#define MSGPACK_LIB_C_CLOUDABI_NAME "cloudlibc"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_LIB_C_CLOUDABI,MSGPACK_LIB_C_CLOUDABI_NAME)
