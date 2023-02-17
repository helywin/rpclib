/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_OS_QNXNTO_H
#define MSGPACK_PREDEF_OS_QNXNTO_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_OS_QNX`

http://en.wikipedia.org/wiki/QNX[QNX] operating system.
Version number available as major, and minor if possible. And
version 4 is specifically detected.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__QNX__+` | {predef_detection}
| `+__QNXNTO__+` | {predef_detection}

| `+_NTO_VERSION+` | V.R.0
| `+__QNX__+` | 4.0.0
|===
*/ // end::reference[]

#define MSGPACK_OS_QNX MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(MSGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__QNX__) || defined(__QNXNTO__) \
    )
#   undef MSGPACK_OS_QNX
#   if !defined(MSGPACK_OS_QNX) && defined(_NTO_VERSION)
#       define MSGPACK_OS_QNX MSGPACK_PREDEF_MAKE_10_VVRR(_NTO_VERSION)
#   endif
#   if !defined(MSGPACK_OS_QNX) && defined(__QNX__)
#       define MSGPACK_OS_QNX MSGPACK_VERSION_NUMBER(4,0,0)
#   endif
#   if !defined(MSGPACK_OS_QNX)
#       define MSGPACK_OS_QNX MSGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if MSGPACK_OS_QNX
#   define MSGPACK_OS_QNX_AVAILABLE
#   include <rpc/msgpack/predef/detail/os_detected.h>
#endif

#define MSGPACK_OS_QNX_NAME "QNX"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_OS_QNX,MSGPACK_OS_QNX_NAME)
