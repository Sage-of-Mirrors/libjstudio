#include "util.hpp"

size_t JStudio::Util::GetNextAligned(size_t value, size_t alignment)
{
	return (value + (alignment - 1)) & ~(alignment - 1);
}
