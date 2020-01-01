
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
