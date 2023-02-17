/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_OS_OS400_H
#define MSGPACK_PREDEF_OS_OS400_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_OS_OS400`

http://en.wikipedia.org/wiki/IBM_i[IBM OS/400] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__OS400__+` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_OS_OS400 MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(MSGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__OS400__) \
    )
#   undef MSGPACK_OS_OS400
#   define MSGPACK_OS_OS400 MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if MSGPACK_OS_OS400
#   define MSGPACK_OS_OS400_AVAILABLE
#   include <rpc/msgpack/predef/detail/os_detected.h>
#endif

#define MSGPACK_OS_OS400_NAME "IBM OS/400"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_OS_OS400,MSGPACK_OS_OS400_NAME)
