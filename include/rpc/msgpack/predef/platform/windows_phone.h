/*
Copyright (c) Microsoft Corporation 2014
Copyright Rene Rivera 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_PLAT_WINDOWS_PHONE_H
#define MSGPACK_PREDEF_PLAT_WINDOWS_PHONE_H

#include <rpc/msgpack/predef/make.h>
#include <rpc/msgpack/predef/os/windows.h>
#include <rpc/msgpack/predef/platform/windows_uwp.h>
#include <rpc/msgpack/predef/version_number.h>

/* tag::reference[]
= `MSGPACK_PLAT_WINDOWS_PHONE`

https://docs.microsoft.com/en-us/windows/uwp/get-started/universal-application-platform-guide[UWP]
for Windows Phone development.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_PLAT_WINDOWS_PHONE MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if MSGPACK_OS_WINDOWS && \
    defined(WINAPI_FAMILY_PHONE_APP) && WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
#   undef MSGPACK_PLAT_WINDOWS_PHONE
#   define MSGPACK_PLAT_WINDOWS_PHONE MSGPACK_VERSION_NUMBER_AVAILABLE
#endif
 
#if MSGPACK_PLAT_WINDOWS_PHONE
#   define MSGPACK_PLAT_WINDOWS_PHONE_AVAILABLE
#   include <rpc/msgpack/predef/detail/platform_detected.h>
#endif

#define MSGPACK_PLAT_WINDOWS_PHONE_NAME "Windows Phone"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_PLAT_WINDOWS_PHONE,MSGPACK_PLAT_WINDOWS_PHONE_NAME)
