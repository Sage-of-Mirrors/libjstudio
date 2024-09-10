#pragma once

#include "types.h"

namespace JStudio
{
	namespace Engine
	{
		float ExtrapolateRepeat(float value, float max);
		float ExtrapolateTurn(float value, float max);
		float ExtrapolateClamp(float value, float max);
	} // namespace Engine
} // namespace JStudio
