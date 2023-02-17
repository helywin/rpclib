/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_LIBRARY_STD_MSL_H
#define MSGPACK_PREDEF_LIBRARY_STD_MSL_H

#include <rpc/msgpack/predef/library/std/_prefix.h>

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_LIB_STD_MSL`

http://www.freescale.com/[Metrowerks] Standard {CPP} Library.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__MSL_CPP__+` | {predef_detection}
| `+__MSL__+` | {predef_detection}

| `+__MSL_CPP__+` | V.R.P
| `+__MSL__+` | V.R.P
|===
*/ // end::reference[]

#define MSGPACK_LIB_STD_MSL MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MSL_CPP__) || defined(__MSL__)
#   undef MSGPACK_LIB_STD_MSL
#   if defined(__MSL_CPP__)
#       define MSGPACK_LIB_STD_MSL MSGPACK_PREDEF_MAKE_0X_VRPP(__MSL_CPP__)
#   else
#       define MSGPACK_LIB_STD_MSL MSGPACK_PREDEF_MAKE_0X_VRPP(__MSL__)
#   endif
#endif

#if MSGPACK_LIB_STD_MSL
#   define MSGPACK_LIB_STD_MSL_AVAILABLE
#endif

#define MSGPACK_LIB_STD_MSL_NAME "Metrowerks"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_LIB_STD_MSL,MSGPACK_LIB_STD_MSL_NAME)
