#ifndef   __DISCOMPLEXITY__HH__
#define   __DISCOMPLEXITY__HH__

#ifdef    WIN32
#include <stdint.h>
typedef int8_t					__INT8_TYPE__;
typedef int16_t					__INT16_TYPE__;
typedef int32_t					__INT32_TYPE__;
typedef int64_t					__INT64_TYPE__;
typedef uint8_t					__UINT8_TYPE__;
typedef uint16_t				__UINT16_TYPE__;
typedef uint32_t				__UINT32_TYPE__;
typedef uint64_t				__UINT64_TYPE__;
#endif // WIN32

#include <string>
#include <iostream>
#include <fstream>

namespace discomplexity
{
	typedef __INT8_TYPE__		int8;
	typedef __INT16_TYPE__		int16;
	typedef __INT32_TYPE__		int32;
	typedef __INT64_TYPE__		int64;
	typedef __UINT8_TYPE__		uint8;
	typedef __UINT16_TYPE__		uint16;
	typedef __UINT32_TYPE__		uint32;
	typedef __UINT64_TYPE__		uint64;
	typedef ::std::string       string;
	typedef unsigned char       byte;
}

#endif // __DISCOMPLEXITY__HH__