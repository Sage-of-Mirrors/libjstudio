#pragma once

#include "types.h"

namespace JStudio
{
	namespace Engine
	{
		enum class EUpdateType
		{
			NONE = 0,
			VOID = 1, // Disable updates for this track.
			IMMEDIATE = 2, // Set the value on this track with an immediate value.
			TIME = 3, // Ramp the track's value based by a given velocity, starting at 0.
			FUNCVALUE_NAME = 0x10, // Unused?
			FUNCVALUE_INDEX = 0x12 // Make the track use a function value object for the value.
		};

		struct TKey
		{
			float Value;
			uint32_t Time;
			EUpdateType Type;
		};
	} // namespace Engine
} // namespace JStudio
