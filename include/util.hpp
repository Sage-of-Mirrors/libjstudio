#pragma once

#include "types.h"

namespace JStudio
{
	namespace Util
	{
		size_t GetNextAligned(size_t value, size_t alignment)
		{
			return (value + (alignment - 1)) & ~(alignment - 1);
		}
	} // namespace Util
} // namespace JStudio
