
#ifndef RECURSION_H
#define RECURSION_H

#include <cstdint>
#include <string>

// CUTOFF = (2 to the power of FLN_NUM_COUNTER_BITS)
// if this exceeds that limit, there is a risk of re-using previous FLN identifiers.
#define CUTOFF 1024

#endif // RECURSION_H


// recursion loop condition
#if __COUNTER__ <= CUTOFF

#include <FILE_LOCAL_NAMESPACE.HPP>
namespace FILE_LOCAL_NAMESPACE
{
	using namespace std;

	inline size_t len()
	{
#if __COUNTER__ > CUTOFF
		// provide a different body for the inline function.
		// if FILE_LOCAL_NAMESPACE is the same as a previous identifier,
		// this will cause an error.
		return FILE_LOCAL_NAMESPACE::string("").length();
#else
		return FILE_LOCAL_NAMESPACE::string().length();
#endif
	}

	inline size_t counter()
	{
		return __COUNTER__;
	}
}

#if __COUNTER__ > CUTOFF

// after recursion has ended
#ifndef RECURSION_H_PART2
#define RECURSION_H_PART2
inline size_t recursion_len() { return FILE_LOCAL_NAMESPACE::len(); }
inline size_t recursion_counter() { return FILE_LOCAL_NAMESPACE::counter(); }
inline size_t recursion_final() { return __COUNTER__; }
#endif

#else // COUNTER > CUTOFF

#include "recursion.h"

#endif // COUNTER > CUTOFF

#endif // COUNTER <= CUTOFF
