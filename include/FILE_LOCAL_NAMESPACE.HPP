/*
//	File Local Namespace
//	Author: Elijah Shadbolt
//	Date Edited: 01/01/2020
//	License: MIT
//	
//	Description
//		Allows you to declare anonymous namespaces in separate header files, avoiding name pollution.
//		The file local namespace should contain aliases (using statements) because other members are
//		not reliably accessable from cpp files accompanying your headers.
//
//	Installation
//		This is a single-file header-only C++ library.
//
//		1. Copy `FILE_LOCAL_NAMESPACE.HPP` into your project.
//		2. Add the directory of the copied file to your project dependencies (`additional include directories` for Visual Studio).
//		3. Include the header file. `#include <FILE_LOCAL_NAMESPACE.HPP>`
//		4. Declare the namespace. `namespace FILE_LOCAL_NAMESPACE { using namespace std; }`
//
//	How it Works
//		The `FILE_LOCAL_NAMESPACE` macro expands to an identifier.
//		Every time this header is included, the `FILE_LOCAL_NAMESPACE` identifier is changed.
//		You can then declare a new namespace with the name `FILE_LOCAL_NAMESPACE`.
//
//	Non-Standard Macro `__COUNTER__`
//		The macro `__COUNTER__` must increment every time it is expanded.
//		This is provided by MSVC.
//
//	Example:

	// example.h

	#pragma once

	#include <chrono>

	#include <FILE_LOCAL_NAMESPACE.HPP>
	namespace FLN
	{
		using namespace std::chrono;
	}

	namespace example
	{
		FLN::seconds get_seconds();
	}



	// example.cpp

	#include "example.h"

	#include <FILE_LOCAL_NAMESPACE.HPP>
	namespace FLN
	{
		using namespace std::chrono;
	}

	namespace example
	{
		FLN::seconds get_seconds()
		{
			return FLN::duration_cast<FLN::seconds>(FLN::milliseconds(3000));
		}
	}

//
//	FLN
//		This header file also defines `FLN` as an alias for `FILE_LOCAL_NAMESPACE`.
//		`FLN` may cause name conflicts because it is a very short identifier, so it is optional, but defined by default.
//		`FLN` is not defined if `FLN_PP_NO_SHORTHAND` is defined before the first time this header is included.
//
//	Don't forget `push_macro`!
//		The MSVC provides `push_macro` and `pop_macro` which can be used to create scoped macros.
//		Example:

	// example2.h

	#pragma once

	#include <chrono>

	constexpr int fln = 5; // something with same identifier that was imported unknowingly

	#include <FILE_LOCAL_NAMESPACE.HPP>
	namespace FILE_LOCAL_NAMESPACE
	{
		using namespace std::chrono;
	}

	#pragma push_macro("fln")
	#define fln FILE_LOCAL_NAMESPACE

	namespace example2
	{
		fln::seconds get_seconds();
	}

	#pragma pop_macro("fln") // fln macro removed, now back to constexpr int fln



	// example2.cpp

	#include "example2.h"

	using namespace std::chrono;

	namespace example2
	{
		seconds get_seconds()
		{
			constexpr int x = fln;
			return seconds(x);
		}
	}

//
//	Limitations
//
//		- There can only be so many FLN namespaces ((2 to the power of FLN_NUM_COUNTER_BITS) / FLN_NUM_COUNTER_BITS).
//			Exceeding this limit may risk doubling up and adding aliases to the other previous namespaces.
//			Currently this limit is 102, because FLN_NUM_COUNTER_BITS == 10.
//		- It may slow down compilation time because of the indeterminate `__COUNTER__` macro being used for identifiers.
//			Compilation time has not been tested.
*/

#ifndef FILE_LOCAL_NAMESPACE_HPP
#define FILE_LOCAL_NAMESPACE_HPP

#define FLN_TOKEN(a) a
#define FLN_CONCAT_TOKEN(a, b) a ## b
#define FLN_CONCAT(a, b) FLN_CONCAT_TOKEN(a, b)

#define FLN_NUM_COUNTER_BITS 10

#define FLN_CONCAT_TOKEN_MANY(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9) a0 ## a1 ## a2 ## a3 ## a4 ## a5 ## a6 ## a7 ## a8 ## a9
#define FLN_CONCAT_MANY(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9) FLN_CONCAT_TOKEN_MANY(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9)

#define FLN_COUNTER FLN_CONCAT_MANY(\
FLN_COUNTER_BIT_09,\
FLN_COUNTER_BIT_08,\
FLN_COUNTER_BIT_07,\
FLN_COUNTER_BIT_06,\
FLN_COUNTER_BIT_05,\
FLN_COUNTER_BIT_04,\
FLN_COUNTER_BIT_03,\
FLN_COUNTER_BIT_02,\
FLN_COUNTER_BIT_01,\
FLN_COUNTER_BIT_00)

#define FILE_LOCAL_NAMESPACE FLN_CONCAT(File_Local_Namespace_, FLN_COUNTER)

#ifndef FLN_PP_NO_SHORTHAND
#define FLN FILE_LOCAL_NAMESPACE
#endif

#endif // FILE_LOCAL_NAMESPACE_HPP



#ifdef FLN_COUNTER_BIT_00
#  undef FLN_COUNTER_BIT_00
#endif
#if (__COUNTER__) & 1
#  define FLN_COUNTER_BIT_00 1
#else
#  define FLN_COUNTER_BIT_00 0
#endif

#ifdef FLN_COUNTER_BIT_01
#  undef FLN_COUNTER_BIT_01
#endif
#if (__COUNTER__ - 1) >> 1 & 1
#  define FLN_COUNTER_BIT_01 1
#else
#  define FLN_COUNTER_BIT_01 0
#endif

#ifdef FLN_COUNTER_BIT_02
#  undef FLN_COUNTER_BIT_02
#endif
#if (__COUNTER__ - 2) >> 2 & 1
#  define FLN_COUNTER_BIT_02 1
#else
#  define FLN_COUNTER_BIT_02 0
#endif

#ifdef FLN_COUNTER_BIT_03
#  undef FLN_COUNTER_BIT_03
#endif
#if (__COUNTER__ - 3) >> 3 & 1
#  define FLN_COUNTER_BIT_03 1
#else
#  define FLN_COUNTER_BIT_03 0
#endif

#ifdef FLN_COUNTER_BIT_04
#  undef FLN_COUNTER_BIT_04
#endif
#if (__COUNTER__ - 4) >> 4 & 1
#  define FLN_COUNTER_BIT_04 1
#else
#  define FLN_COUNTER_BIT_04 0
#endif

#ifdef FLN_COUNTER_BIT_05
#  undef FLN_COUNTER_BIT_05
#endif
#if (__COUNTER__ - 5) >> 5 & 1
#  define FLN_COUNTER_BIT_05 1
#else
#  define FLN_COUNTER_BIT_05 0
#endif

#ifdef FLN_COUNTER_BIT_06
#  undef FLN_COUNTER_BIT_06
#endif
#if (__COUNTER__ - 6) >> 6 & 1
#  define FLN_COUNTER_BIT_06 1
#else
#  define FLN_COUNTER_BIT_06 0
#endif

#ifdef FLN_COUNTER_BIT_07
#  undef FLN_COUNTER_BIT_07
#endif
#if (__COUNTER__ - 7) >> 7 & 1
#  define FLN_COUNTER_BIT_07 1
#else
#  define FLN_COUNTER_BIT_07 0
#endif

#ifdef FLN_COUNTER_BIT_08
#  undef FLN_COUNTER_BIT_08
#endif
#if (__COUNTER__ - 8) >> 8 & 1
#  define FLN_COUNTER_BIT_08 1
#else
#  define FLN_COUNTER_BIT_08 0
#endif

#ifdef FLN_COUNTER_BIT_09
#  undef FLN_COUNTER_BIT_09
#endif
#if (__COUNTER__ - 9) >> 9 & 1
#  define FLN_COUNTER_BIT_09 1
#else
#  define FLN_COUNTER_BIT_09 0
#endif
