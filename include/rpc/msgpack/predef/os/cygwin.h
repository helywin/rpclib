/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_OS_CYGWIN_H
#define MSGPACK_PREDEF_OS_CYGWIN_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_OS_CYGWIN`

http://en.wikipedia.org/wiki/Cygwin[Cygwin] evironment.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__CYGWIN__+` | {predef_detection}

| `CYGWIN_VERSION_API_MAJOR`, `CYGWIN_VERSION_API_MINOR` | V.R.0
|===
*/ // end::reference[]

#define MSGPACK_OS_CYGWIN MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(MSGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__CYGWIN__) \
    )
#   include <cygwin/version.h>
#   undef MSGPACK_OS_CYGWIN
#   define MSGPACK_OS_CYGWIN \
        MSGPACK_VERSION_NUMBER(CYGWIN_VERSION_API_MAJOR,\
                             CYGWIN_VERSION_API_MINOR, 0)
#endif

#if MSGPACK_OS_CYGWIN
#   define MSGPACK_OS_CYGWIN_AVAILABLE
#   include <rpc/msgpack/predef/detail/os_detected.h>
#endif

#define MSGPACK_OS_CYGWIN_NAME "Cygwin"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_OS_CYGWIN,MSGPACK_OS_CYGWIN_NAME)
