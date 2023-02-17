/*
Copyright Rene Rivera 2015-2019
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_PLAT_ANDROID_H
#define MSGPACK_PREDEF_PLAT_ANDROID_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_PLAT_ANDROID`

http://en.wikipedia.org/wiki/Android_%28operating_system%29[Android] platform.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__ANDROID__+` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_PLAT_ANDROID MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__ANDROID__)
#   undef MSGPACK_PLAT_ANDROID
#   define MSGPACK_PLAT_ANDROID MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if MSGPACK_PLAT_ANDROID
#   define MSGPACK_PLAT_ANDROID_AVAILABLE
#   include <rpc/msgpack/predef/detail/platform_detected.h>
#endif

#define MSGPACK_PLAT_ANDROID_NAME "Android"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_PLAT_ANDROID,MSGPACK_PLAT_ANDROID_NAME)
