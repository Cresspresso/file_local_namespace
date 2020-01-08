
#include "recursion_test.hpp"



#define ENABLE_RECURSION_TEST
#ifdef ENABLE_RECURSION_TEST

#include <cassert>
#include <cstdio>

#include "recursion.h"

void recursion_test()
{
	assert(recursion_len() == 0);
	assert(recursion_counter() == recursion_counter());
	assert(recursion_final() == recursion_final());
	assert(recursion_final() == recursion_counter() + 2);
}

#else

void recursion_test() {}

#endif

