
#pragma once

#include <string>

#include <FILE_LOCAL_NAMESPACE.HPP>
namespace FILE_LOCAL_NAMESPACE
{
	using namespace std;
}

namespace example3_utils
{
	template<class T>
	std::string to_string(T value)
	{
		return FILE_LOCAL_NAMESPACE::to_string(value + 1);
	}
}
