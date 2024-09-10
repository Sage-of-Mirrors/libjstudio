#include "engine/value/extrapolation.hpp"

#include <cmath>

float JStudio::Engine::ExtrapolateRepeat(float value, float max)
{
	float result = std::fmodf(value, max);
	return result < 0.0f ? result + max : result;
} // ExtrapolateRepeat

float JStudio::Engine::ExtrapolateTurn(float value, float max)
{
	float doubleMax = max * 2.0f;
	float valOnDoubleMax = ExtrapolateRepeat(value, doubleMax);

	return valOnDoubleMax >= max ? doubleMax - valOnDoubleMax : valOnDoubleMax;
} // ExtrapolateTurn

float JStudio::Engine::ExtrapolateClamp(float value, float max)
{
	if (value <= 0.0f)
	{
		return 0.0f;
	}
	else if (value > max)
	{
		return max;
	}
	else
	{
		return value;
	}
} // ExtrapolateClamp
