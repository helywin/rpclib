/*
Copyright Rene Rivera 2012-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_OS_BSD_FREE_H
#define MSGPACK_PREDEF_OS_BSD_FREE_H

#include <rpc/msgpack/predef/os/bsd.h>

/* tag::reference[]
= `MSGPACK_OS_BSD_FREE`

http://en.wikipedia.org/wiki/Freebsd[FreeBSD] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__FreeBSD__+` | {predef_detection}

| `+__FreeBSD_version+` | V.R.P
|===
*/ // end::reference[]

#define MSGPACK_OS_BSD_FREE MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(MSGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__FreeBSD__) \
    )
#   ifndef MSGPACK_OS_BSD_AVAILABLE
#       undef MSGPACK_OS_BSD
#       define MSGPACK_OS_BSD MSGPACK_VERSION_NUMBER_AVAILABLE
#       define MSGPACK_OS_BSD_AVAILABLE
#   endif
#   undef MSGPACK_OS_BSD_FREE
#   include <sys/param.h>
#   if defined(__FreeBSD_version)
#       if __FreeBSD_version == 491000
#           define MSGPACK_OS_BSD_FREE \
                MSGPACK_VERSION_NUMBER(4, 10, 0)
#       elif __FreeBSD_version == 492000
#           define MSGPACK_OS_BSD_FREE \
                MSGPACK_VERSION_NUMBER(4, 11, 0)
#       elif __FreeBSD_version < 500000
#           define MSGPACK_OS_BSD_FREE \
                MSGPACK_PREDEF_MAKE_10_VRPPPP(__FreeBSD_version)
#       else
#           define MSGPACK_OS_BSD_FREE \
                MSGPACK_PREDEF_MAKE_10_VVRRPPP(__FreeBSD_version)
#       endif
#   else
#       define MSGPACK_OS_BSD_FREE MSGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if MSGPACK_OS_BSD_FREE
#   define MSGPACK_OS_BSD_FREE_AVAILABLE
#   include <rpc/msgpack/predef/detail/os_detected.h>
#endif

#define MSGPACK_OS_BSD_FREE_NAME "Free BSD"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_OS_BSD_FREE,MSGPACK_OS_BSD_FREE_NAME)
