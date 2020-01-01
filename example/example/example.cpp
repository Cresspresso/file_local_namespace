
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
