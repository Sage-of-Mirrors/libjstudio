#pragma once

#include "types.h"

namespace JStudio
{
	namespace Util
	{
		size_t GetAlignedOffset(size_t pos, size_t alignment)
		{
			return (pos + (alignment - 1)) & ~(alignment - 1);
		}
	} // namespace Util
} // namespace JStudio
