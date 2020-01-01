
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
