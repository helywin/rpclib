/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_LIBRARY_STD_LIBCOMO_H
#define MSGPACK_PREDEF_LIBRARY_STD_LIBCOMO_H

#include <rpc/msgpack/predef/library/std/_prefix.h>

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_LIB_STD_COMO`

http://www.comeaucomputing.com/libcomo/[Comeau Computing] Standard {CPP} Library.
Version number available as major.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__LIBCOMO__+` | {predef_detection}

| `+__LIBCOMO_VERSION__+` | V.0.0
|===
*/ // end::reference[]

#define MSGPACK_LIB_STD_COMO MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__LIBCOMO__)
#   undef MSGPACK_LIB_STD_COMO
#   define MSGPACK_LIB_STD_COMO MSGPACK_VERSION_NUMBER(__LIBCOMO_VERSION__,0,0)
#endif

#if MSGPACK_LIB_STD_COMO
#   define MSGPACK_LIB_STD_COMO_AVAILABLE
#endif

#define MSGPACK_LIB_STD_COMO_NAME "Comeau Computing"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_LIB_STD_COMO,MSGPACK_LIB_STD_COMO_NAME)
