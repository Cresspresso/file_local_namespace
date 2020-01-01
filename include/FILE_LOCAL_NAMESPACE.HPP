/*
//	File Local Namespace
//	Author: Elijah Shadbolt
//	Date Edited: 01/01/2020
//	License: MIT
//	
//	Allows you to declare anonymous namespaces in separate header files, avoiding name pollution.
//	The file local namespace should contain aliases (using statements) because other members are
//	not reliably accessable from your headers' accompanying cpp files.
//
//	How it Works
//		The FILE_LOCAL_NAMESPACE macro expands to an identifier.
//		Every time this header is included, the FILE_LOCAL_NAMESPACE identifier is changed.
//		You can then declare a new namespace with the name FILE_LOCAL_NAMESPACE.
//
//	Example:

	// example.h

	#pragma once

	#include <chrono>

	#include "FILE_LOCAL_NAMESPACE.HPP"
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

	#include "FILE_LOCAL_NAMESPACE.HPP"
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
//		This header file also defines FLN as an alias for FILE_LOCAL_NAMESPACE.
//		'FLN' may cause name conflicts because it is a very short identifier, so it is optional.
//		FLN is not defined if FLN_PP_NO_SHORTHAND is defined before the first time this header is included.
//
//	Don't forget push_macro!
//		The MSVC provides push_macro and pop_macro which can be used to create scoped macros.
//		Example:

	// example2.h

	#pragma once

	#include <chrono>

	constexpr int fln = 5; // something with same identifier that was imported unknowingly

	#include "FILE_LOCAL_NAMESPACE.HPP"
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
*/

#ifndef FILE_LOCAL_NAMESPACE_HPP
#define FILE_LOCAL_NAMESPACE_HPP

#define FLN_TOKEN(a) a
#define FLN_CONCAT_TOKEN(a, b) a ## b
#define FLN_CONCAT(a, b) FLN_CONCAT_TOKEN(a, b)

#define FLN_CONCAT_TOKEN_MANY(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9) a0 ## a1 ## a2 ## a3 ## a4 ## a5 ## a6 ## a7 ## a8 ## a9
#define FLN_CONCAT_MANY(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9) FLN_CONCAT_TOKEN_MANY(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9)

#define FLN_COUNTER FLN_CONCAT_MANY(\
FLN_COUNTER_BIT_0,\
FLN_COUNTER_BIT_1,\
FLN_COUNTER_BIT_2,\
FLN_COUNTER_BIT_3,\
FLN_COUNTER_BIT_4,\
FLN_COUNTER_BIT_5,\
FLN_COUNTER_BIT_6,\
FLN_COUNTER_BIT_7,\
FLN_COUNTER_BIT_8,\
FLN_COUNTER_BIT_9)

#define FILE_LOCAL_NAMESPACE FLN_CONCAT(File_Local_Namespace_, FLN_COUNTER)

#ifndef FLN_PP_NO_SHORTHAND
#define FLN FILE_LOCAL_NAMESPACE
#endif

#endif // FILE_LOCAL_NAMESPACE_HPP



#ifdef FLN_COUNTER_BIT_0
#  undef FLN_COUNTER_BIT_0
#endif
#if (__COUNTER__) & 1
#  define FLN_COUNTER_BIT_0 1
#else
#  define FLN_COUNTER_BIT_0 0
#endif

#ifdef FLN_COUNTER_BIT_1
#  undef FLN_COUNTER_BIT_1
#endif
#if (__COUNTER__ - 1) >> 1 & 1
#  define FLN_COUNTER_BIT_1 1
#else
#  define FLN_COUNTER_BIT_1 0
#endif

#ifdef FLN_COUNTER_BIT_2
#  undef FLN_COUNTER_BIT_2
#endif
#if (__COUNTER__ - 2) >> 2 & 1
#  define FLN_COUNTER_BIT_2 1
#else
#  define FLN_COUNTER_BIT_2 0
#endif

#ifdef FLN_COUNTER_BIT_3
#  undef FLN_COUNTER_BIT_3
#endif
#if (__COUNTER__ - 3) >> 3 & 1
#  define FLN_COUNTER_BIT_3 1
#else
#  define FLN_COUNTER_BIT_3 0
#endif

#ifdef FLN_COUNTER_BIT_4
#  undef FLN_COUNTER_BIT_4
#endif
#if (__COUNTER__ - 4) >> 4 & 1
#  define FLN_COUNTER_BIT_4 1
#else
#  define FLN_COUNTER_BIT_4 0
#endif

#ifdef FLN_COUNTER_BIT_5
#  undef FLN_COUNTER_BIT_5
#endif
#if (__COUNTER__ - 5) >> 5 & 1
#  define FLN_COUNTER_BIT_5 1
#else
#  define FLN_COUNTER_BIT_5 0
#endif

#ifdef FLN_COUNTER_BIT_6
#  undef FLN_COUNTER_BIT_6
#endif
#if (__COUNTER__ - 6) >> 6 & 1
#  define FLN_COUNTER_BIT_6 1
#else
#  define FLN_COUNTER_BIT_6 0
#endif

#ifdef FLN_COUNTER_BIT_7
#  undef FLN_COUNTER_BIT_7
#endif
#if (__COUNTER__ - 7) >> 7 & 1
#  define FLN_COUNTER_BIT_7 1
#else
#  define FLN_COUNTER_BIT_7 0
#endif

#ifdef FLN_COUNTER_BIT_8
#  undef FLN_COUNTER_BIT_8
#endif
#if (__COUNTER__ - 8) >> 8 & 1
#  define FLN_COUNTER_BIT_8 1
#else
#  define FLN_COUNTER_BIT_8 0
#endif

#ifdef FLN_COUNTER_BIT_9
#  undef FLN_COUNTER_BIT_9
#endif
#if (__COUNTER__ - 9) >> 9 & 1
#  define FLN_COUNTER_BIT_9 1
#else
#  define FLN_COUNTER_BIT_9 0
#endif
