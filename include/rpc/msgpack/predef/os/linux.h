/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_OS_LINUX_H
#define MSGPACK_PREDEF_OS_LINUX_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_OS_LINUX`

http://en.wikipedia.org/wiki/Linux[Linux] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `linux` | {predef_detection}
| `+__linux+` | {predef_detection}
| `+__linux__+` | {predef_detection}
| `+__gnu_linux__+` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_OS_LINUX MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(MSGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(linux) || defined(__linux) || \
    defined(__linux__) || defined(__gnu_linux__) \
    )
#   undef MSGPACK_OS_LINUX
#   define MSGPACK_OS_LINUX MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if MSGPACK_OS_LINUX
#   define MSGPACK_OS_LINUX_AVAILABLE
#   include <rpc/msgpack/predef/detail/os_detected.h>
#endif

#define MSGPACK_OS_LINUX_NAME "Linux"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_OS_LINUX,MSGPACK_OS_LINUX_NAME)
