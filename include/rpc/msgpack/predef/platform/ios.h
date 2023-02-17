/*
Copyright Ruslan Baratov 2017
Copyright Rene Rivera 2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_PLAT_IOS_H
#define MSGPACK_PREDEF_PLAT_IOS_H

#include <rpc/msgpack/predef/os/ios.h> // MSGPACK_OS_IOS
#include <rpc/msgpack/predef/version_number.h> // MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

/* tag::reference[]
= `MSGPACK_PLAT_IOS_DEVICE`
= `MSGPACK_PLAT_IOS_SIMULATOR`

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `TARGET_IPHONE_SIMULATOR` | {predef_detection}
| `TARGET_OS_SIMULATOR` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_PLAT_IOS_DEVICE MSGPACK_VERSION_NUMBER_NOT_AVAILABLE
#define MSGPACK_PLAT_IOS_SIMULATOR MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

// https://opensource.apple.com/source/CarbonHeaders/CarbonHeaders-18.1/TargetConditionals.h
#if MSGPACK_OS_IOS
#    include <TargetConditionals.h>
#    if defined(TARGET_OS_SIMULATOR) && (TARGET_OS_SIMULATOR == 1)
#        undef MSGPACK_PLAT_IOS_SIMULATOR
#        define MSGPACK_PLAT_IOS_SIMULATOR MSGPACK_VERSION_NUMBER_AVAILABLE
#    elif defined(TARGET_IPHONE_SIMULATOR) && (TARGET_IPHONE_SIMULATOR == 1)
#        undef MSGPACK_PLAT_IOS_SIMULATOR
#        define MSGPACK_PLAT_IOS_SIMULATOR MSGPACK_VERSION_NUMBER_AVAILABLE
#    else
#        undef MSGPACK_PLAT_IOS_DEVICE
#        define MSGPACK_PLAT_IOS_DEVICE MSGPACK_VERSION_NUMBER_AVAILABLE
#    endif
#endif

#if MSGPACK_PLAT_IOS_SIMULATOR
#    define MSGPACK_PLAT_IOS_SIMULATOR_AVAILABLE
#    include <rpc/msgpack/predef/detail/platform_detected.h>
#endif

#if MSGPACK_PLAT_IOS_DEVICE
#    define MSGPACK_PLAT_IOS_DEVICE_AVAILABLE
#    include <rpc/msgpack/predef/detail/platform_detected.h>
#endif

#define MSGPACK_PLAT_IOS_SIMULATOR_NAME "iOS Simulator"
#define MSGPACK_PLAT_IOS_DEVICE_NAME "iOS Device"

#endif // MSGPACK_PREDEF_PLAT_IOS_H

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_PLAT_IOS_SIMULATOR,MSGPACK_PLAT_IOS_SIMULATOR_NAME)
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_PLAT_IOS_DEVICE,MSGPACK_PLAT_IOS_DEVICE_NAME)
