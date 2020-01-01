
# File Local Namespace

Author: Elijah Shadbolt
Date Edited: 01/01/2020
License: MIT

Allows you to declare anonymous namespaces in separate header files, avoiding name pollution.

The file local namespace should contain aliases (using statements) because other members are not reliably accessable from your headers' accompanying cpp files.

## How it Works

The FILE_LOCAL_NAMESPACE macro expands to an identifier.

Every time this header is included, the FILE_LOCAL_NAMESPACE identifier is changed.

You can then declare a new namespace with the name FILE_LOCAL_NAMESPACE.

### Example

```cpp
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
```

```cpp
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
```

## FLN

This header file also defines FLN as an alias for FILE_LOCAL_NAMESPACE.
'FLN' may cause name conflicts because it is a very short identifier, so it is optional.
FLN is not defined if FLN_PP_NO_SHORTHAND is defined before the first time this header is included.

### Don't forget push_macro!

The MSVC provides push_macro and pop_macro which can be used to create scoped macros.

### Example 2

```cpp
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
```

```cpp
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
```