/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_OS_HPUX_H
#define MSGPACK_PREDEF_OS_HPUX_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_OS_HPUX`

http://en.wikipedia.org/wiki/HP-UX[HP-UX] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `hpux` | {predef_detection}
| `+_hpux+` | {predef_detection}
| `+__hpux+` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_OS_HPUX MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(MSGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(hpux) || defined(_hpux) || defined(__hpux) \
    )
#   undef MSGPACK_OS_HPUX
#   define MSGPACK_OS_HPUX MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if MSGPACK_OS_HPUX
#   define MSGPACK_OS_HPUX_AVAILABLE
#   include <rpc/msgpack/predef/detail/os_detected.h>
#endif

#define MSGPACK_OS_HPUX_NAME "HP-UX"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_OS_HPUX,MSGPACK_OS_HPUX_NAME)
