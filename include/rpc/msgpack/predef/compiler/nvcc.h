/*
Copyright Benjamin Worpitz 2018
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_COMPILER_NVCC_H
#define MSGPACK_PREDEF_COMPILER_NVCC_H

#include <rpc/msgpack/predef/version_number.h>
#include <rpc/msgpack/predef/make.h>

/* tag::reference[]
= `MSGPACK_COMP_NVCC`

https://en.wikipedia.org/wiki/NVIDIA_CUDA_Compiler[NVCC] compiler.
Version number available as major, minor, and patch beginning with version 7.5.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__NVCC__+` | {predef_detection}

| `+__CUDACC_VER_MAJOR__+`, `+__CUDACC_VER_MINOR__+`, `+__CUDACC_VER_BUILD__+` | V.R.P
|===
*/ // end::reference[]

#define MSGPACK_COMP_NVCC MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__NVCC__)
#   if !defined(__CUDACC_VER_MAJOR__) || !defined(__CUDACC_VER_MINOR__) || !defined(__CUDACC_VER_BUILD__)
#       define MSGPACK_COMP_NVCC_DETECTION MSGPACK_VERSION_NUMBER_AVAILABLE
#   else
#       define MSGPACK_COMP_NVCC_DETECTION MSGPACK_VERSION_NUMBER(__CUDACC_VER_MAJOR__, __CUDACC_VER_MINOR__, __CUDACC_VER_BUILD__)
#   endif
#endif

#ifdef MSGPACK_COMP_NVCC_DETECTION
/*
Always define MSGPACK_COMP_NVCC instead of MSGPACK_COMP_NVCC_EMULATED
The nvcc compilation process is somewhat special as can be read here:
https://docs.nvidia.com/cuda/cuda-compiler-driver-nvcc/index.html#cuda-compilation-trajectory
The nvcc compiler precompiles the input two times. Once for the device code
being compiled by the cicc device compiler and once for the host code
compiled by the real host compiler. NVCC uses gcc/clang/msvc/...
depending on the host compiler being set on the command line.

Predef (as a preprocessor only lib) detects the one doing the preprocessing
as compiler and expects it to be the one doing the real compilation.
This is not true for NVCC which is only doing the preprocessing and which
is using another compiler for parts of its work. So for NVCC it should be
allowed to set MSGPACK_COMP_NVCC additionally to the already detected host
compiler because both is true: It is gcc/clang/... compiling the code, but it
is also NVCC doing the preprocessing and adding some other quirks you may
want to detect.

This behavior is similar to what boost config is doing in `select_compiler_config.hpp`.
There the NVCC detection is not handled as a real compiler (part of the
#if-#elif) but as additional option before the real compiler.
*/
#   undef MSGPACK_COMP_NVCC
#   define MSGPACK_COMP_NVCC MSGPACK_COMP_NVCC_DETECTION
#   define MSGPACK_COMP_NVCC_AVAILABLE
#   include <rpc/msgpack/predef/detail/comp_detected.h>
#endif

#define MSGPACK_COMP_NVCC_NAME "NVCC"

#endif

#include <rpc/msgpack/predef/detail/test.h>
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_COMP_NVCC,MSGPACK_COMP_NVCC_NAME)
