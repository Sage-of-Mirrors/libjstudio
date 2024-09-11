#pragma once

#include "types.h"

#include <vector>
#include <functional>

namespace JStudio
{
	namespace Util
	{
		template<class InputIt, class UnaryPred>
		InputIt find_first_if(InputIt begin, InputIt end, UnaryPred pred)
		{
			InputIt result = end;

			for (InputIt i = begin; i != end; i++)
			{
				if (!pred(*i))
				{
					break;
				}

				result = i;
			}

			return result;
		}

		size_t GetNextAligned(size_t value, size_t alignment);
	} // namespace Util
} // namespace JStudio
