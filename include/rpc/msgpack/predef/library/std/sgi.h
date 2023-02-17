/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_LIBRARY_STD_SGI_H
#define MSGPACK_PREDEF_LIBRARY_STD_SGI_H

#include <rpc/msgpack/predef/library/std/_prefix.h>

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_LIB_STD_SGI`

http://www.sgi.com/tech/stl/[SGI] Standard {CPP} library.
If available version number as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__STL_CONFIG_H+` | {predef_detection}

| `+__SGI_STL+` | V.R.P
|===
*/ // end::reference[]

#define MSGPACK_LIB_STD_SGI MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__STL_CONFIG_H)
#   undef MSGPACK_LIB_STD_SGI
#   if defined(__SGI_STL)
#       define MSGPACK_LIB_STD_SGI MSGPACK_PREDEF_MAKE_0X_VRP(__SGI_STL)
#   else
#       define MSGPACK_LIB_STD_SGI MSGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if MSGPACK_LIB_STD_SGI
#   define MSGPACK_LIB_STD_SGI_AVAILABLE
#endif

#define MSGPACK_LIB_STD_SGI_NAME "SGI"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_LIB_STD_SGI,MSGPACK_LIB_STD_SGI_NAME)
