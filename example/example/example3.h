
#pragma once

#include "example3_utils.hpp"

#include <FILE_LOCAL_NAMESPACE.HPP>
namespace FILE_LOCAL_NAMESPACE
{
	using namespace example3_utils;
}

namespace example3
{
	inline std::string to_string(int value)
	{
		return FILE_LOCAL_NAMESPACE::to_string(value + 1);
	}
}
