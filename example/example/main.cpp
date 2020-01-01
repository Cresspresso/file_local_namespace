
#include <cassert>
#include <cstdio>

#include "example.h"
#include "example2.h"
#include "example3.h"

int main()
{
	assert(example::get_seconds().count() == 3);
	assert(example2::get_seconds().count() == 5);
	assert(example3::to_string(5) == std::string("7"));
	printf_s("done\n");
}
