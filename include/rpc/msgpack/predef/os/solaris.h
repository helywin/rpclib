/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_OS_SOLARIS_H
#define MSGPACK_PREDEF_OS_SOLARIS_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_OS_SOLARIS`

http://en.wikipedia.org/wiki/Solaris_Operating_Environment[Solaris] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `sun` | {predef_detection}
| `+__sun+` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_OS_SOLARIS MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(MSGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(sun) || defined(__sun) \
    )
#   undef MSGPACK_OS_SOLARIS
#   define MSGPACK_OS_SOLARIS MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if MSGPACK_OS_SOLARIS
#   define MSGPACK_OS_SOLARIS_AVAILABLE
#   include <rpc/msgpack/predef/detail/os_detected.h>
#endif

#define MSGPACK_OS_SOLARIS_NAME "Solaris"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_OS_SOLARIS,MSGPACK_OS_SOLARIS_NAME)
