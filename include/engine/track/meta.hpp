#pragma once

#include "types.h"

#include <string>
#include <vector>

namespace JStudio
{
	namespace Engine
	{
		struct TTrackMetadata
		{
			std::string Name;
			std::vector<int32_t> Keys;
		};

		struct TDirectorMetadata
		{
			std::string Name;
			std::vector<TTrackMetadata> Tracks;
		};
	} // namespace Engine
} // namespace JStudio
