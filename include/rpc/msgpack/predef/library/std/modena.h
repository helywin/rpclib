/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_LIBRARY_STD_MODENA_H
#define MSGPACK_PREDEF_LIBRARY_STD_MODENA_H

#include <rpc/msgpack/predef/library/std/_prefix.h>

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_LIB_STD_MSIPL`

http://modena.us/[Modena Software Lib++] Standard {CPP} Library.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `MSIPL_COMPILE_H` | {predef_detection}
| `+__MSIPL_COMPILE_H+` | {predef_detection}
|===
*/ // end::reference[]

#define MSGPACK_LIB_STD_MSIPL MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(MSIPL_COMPILE_H) || defined(__MSIPL_COMPILE_H)
#   undef MSGPACK_LIB_STD_MSIPL
#   define MSGPACK_LIB_STD_MSIPL MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if MSGPACK_LIB_STD_MSIPL
#   define MSGPACK_LIB_STD_MSIPL_AVAILABLE
#endif

#define MSGPACK_LIB_STD_MSIPL_NAME "Modena Software Lib++"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_LIB_STD_MSIPL,MSGPACK_LIB_STD_MSIPL_NAME)
