/*
Copyright Rene Ferdinand Rivera Morell 2020-2021
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_OTHER_WORD_SIZE_H
#define MSGPACK_PREDEF_OTHER_WORD_SIZE_H

#include <rpc/msgpack/predef/architecture.h>
#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_ARCH_WORD_BITS`

Detects the native word size, in bits, for the current architecture. There are
two types of macros for this detection:

* `MSGPACK_ARCH_WORD_BITS`, gives the number of word size bits
  (16, 32, 64).
* `MSGPACK_ARCH_WORD_BITS_16`, `MSGPACK_ARCH_WORD_BITS_32`, and
  `MSGPACK_ARCH_WORD_BITS_64`, indicate when the given word size is
  detected.

They allow for both single checks and direct use of the size in code.

NOTE: The word size is determined manually on each architecture. Hence use of
the `wordsize.h` header will also include all the architecture headers.

*/ // end::reference[]

#if !defined(MSGPACK_ARCH_WORD_BITS_64)
#   define MSGPACK_ARCH_WORD_BITS_64 MSGPACK_VERSION_NUMBER_NOT_AVAILABLE
#elif !defined(MSGPACK_ARCH_WORD_BITS)
#   define MSGPACK_ARCH_WORD_BITS 64
#endif

#if !defined(MSGPACK_ARCH_WORD_BITS_32)
#   define MSGPACK_ARCH_WORD_BITS_32 MSGPACK_VERSION_NUMBER_NOT_AVAILABLE
#elif !defined(MSGPACK_ARCH_WORD_BITS)
#	  define MSGPACK_ARCH_WORD_BITS 32
#endif

#if !defined(MSGPACK_ARCH_WORD_BITS_16)
#   define MSGPACK_ARCH_WORD_BITS_16 MSGPACK_VERSION_NUMBER_NOT_AVAILABLE
#elif !defined(MSGPACK_ARCH_WORD_BITS)
#   define MSGPACK_ARCH_WORD_BITS 16
#endif

#if !defined(MSGPACK_ARCH_WORD_BITS)
#   define MSGPACK_ARCH_WORD_BITS 0
#endif

#define MSGPACK_ARCH_WORD_BITS_NAME "Word Bits"
#define MSGPACK_ARCH_WORD_BITS_16_NAME "16-bit Word Size"
#define MSGPACK_ARCH_WORD_BITS_32_NAME "32-bit Word Size"
#define MSGPACK_ARCH_WORD_BITS_64_NAME "64-bit Word Size"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_ARCH_WORD_BITS,MSGPACK_ARCH_WORD_BITS_NAME)

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_ARCH_WORD_BITS_16,MSGPACK_ARCH_WORD_BITS_16_NAME)

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_ARCH_WORD_BITS_32,MSGPACK_ARCH_WORD_BITS_32_NAME)

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_ARCH_WORD_BITS_64,MSGPACK_ARCH_WORD_BITS_64_NAME)
