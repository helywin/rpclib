/*
Copyright James E. King III, 2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_PLAT_WINDOWS_SYSTEM_H
#define MSGPACK_PREDEF_PLAT_WINDOWS_SYSTEM_H

#include <rpc/msgpack/predef/make.h>
#include <rpc/msgpack/predef/os/windows.h>
#include <rpc/msgpack/predef/platform/windows_uwp.h>
#include <rpc/msgpack/predef/version_number.h>

/* tag::reference[]
= `MSGPACK_PLAT_WINDOWS_SYSTEM`

https://docs.microsoft.com/en-us/windows/uwp/get-started/universal-application-platform-guide[UWP]
for Windows System development.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `WINAPI_FAMILY == WINAPI_FAMILY_SYSTEM` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_PLAT_WINDOWS_SYSTEM MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if MSGPACK_OS_WINDOWS && \
    defined(WINAPI_FAMILY_SYSTEM) && WINAPI_FAMILY == WINAPI_FAMILY_SYSTEM
#   undef MSGPACK_PLAT_WINDOWS_SYSTEM
#   define MSGPACK_PLAT_WINDOWS_SYSTEM MSGPACK_VERSION_NUMBER_AVAILABLE
#endif
 
#if MSGPACK_PLAT_WINDOWS_SYSTEM
#   define MSGPACK_PLAT_WINDOWS_SYSTEM_AVAILABLE
#   include <rpc/msgpack/predef/detail/platform_detected.h>
#endif

#define MSGPACK_PLAT_WINDOWS_SYSTEM_NAME "Windows Drivers and Tools"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_PLAT_WINDOWS_SYSTEM,MSGPACK_PLAT_WINDOWS_SYSTEM_NAME)
