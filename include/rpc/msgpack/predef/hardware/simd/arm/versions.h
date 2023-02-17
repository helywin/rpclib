/*
Copyright Charly Chevalier 2015
Copyright Joel Falcou 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_HARDWARE_SIMD_ARM_VERSIONS_H
#define MSGPACK_PREDEF_HARDWARE_SIMD_ARM_VERSIONS_H

#include <rpc/msgpack/predef/version_number.h>

/* tag::reference[]
= `MSGPACK_HW_SIMD_ARM_*_VERSION`

Those defines represent ARM SIMD extensions versions.

NOTE: You *MUST* compare them with the predef `MSGPACK_HW_SIMD_ARM`.
*/ // end::reference[]

// ---------------------------------

/* tag::reference[]
= `MSGPACK_HW_SIMD_ARM_NEON_VERSION`

The https://en.wikipedia.org/wiki/ARM_architecture#Advanced_SIMD_.28NEON.29[NEON]
ARM extension version number.

Version number is: *1.0.0*.
*/ // end::reference[]
#define MSGPACK_HW_SIMD_ARM_NEON_VERSION MSGPACK_VERSION_NUMBER(1, 0, 0)

/* tag::reference[]

*/ // end::reference[]

#endif
