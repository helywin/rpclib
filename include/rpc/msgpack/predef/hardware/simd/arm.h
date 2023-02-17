/*
Copyright Charly Chevalier 2015
Copyright Joel Falcou 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_HARDWARE_SIMD_ARM_H
#define MSGPACK_PREDEF_HARDWARE_SIMD_ARM_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/hardware/simd/arm/versions.h>

/* tag::reference[]
= `MSGPACK_HW_SIMD_ARM`

The SIMD extension for ARM (*if detected*).
Version number depends on the most recent detected extension.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__ARM_NEON__+` | {predef_detection}
| `+__aarch64__+` | {predef_detection}
| `+_M_ARM+` | {predef_detection}
| `+_M_ARM64+` | {predef_detection}
|===

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__ARM_NEON__+` | MSGPACK_HW_SIMD_ARM_NEON_VERSION
| `+__aarch64__+` | MSGPACK_HW_SIMD_ARM_NEON_VERSION
| `+_M_ARM+` | MSGPACK_HW_SIMD_ARM_NEON_VERSION
| `+_M_ARM64+` | MSGPACK_HW_SIMD_ARM_NEON_VERSION
|===

*/ // end::reference[]

#define MSGPACK_HW_SIMD_ARM MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#undef MSGPACK_HW_SIMD_ARM
#if !defined(MSGPACK_HW_SIMD_ARM) && (defined(__ARM_NEON__) || defined(__aarch64__) || defined (_M_ARM) || defined (_M_ARM64))
#   define MSGPACK_HW_SIMD_ARM MSGPACK_HW_SIMD_ARM_NEON_VERSION
#endif

#if !defined(MSGPACK_HW_SIMD_ARM)
#   define MSGPACK_HW_SIMD_ARM MSGPACK_VERSION_NUMBER_NOT_AVAILABLE
#else
#   define MSGPACK_HW_SIMD_ARM_AVAILABLE
#endif

#define MSGPACK_HW_SIMD_ARM_NAME "ARM SIMD"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_HW_SIMD_ARM, MSGPACK_HW_SIMD_ARM_NAME)
