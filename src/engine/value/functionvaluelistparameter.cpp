#include "engine/value/functionvaluelistparameter.hpp"

#include <bstream.h>
#include <cmath>

constexpr float SECONDS_TO_FRAMES = 30.0f;
constexpr float FRAMES_TO_SECONDS = 1.0f / 30.0f;

JStudio::Engine::TFunctionValueAttributeSet JStudio::Engine::TFunctionValueListParameter::GetAttributeSet()
{
	return TFunctionValueAttributeSet() =
	{
		nullptr,
		this,
		this
	};
} // TFunctionValueListParameter::GetAttributeSet

float JStudio::Engine::TFunctionValueListParameter::Evaluate(int32_t frame)
{
	return 0.0f;
} // TFunctionValueListParameter::Evaluate

void JStudio::Engine::TFunctionValueListParameter::LoadData(bStream::CStream* stream)
{
	uint32_t keyCount = stream->readUInt32();

	for (uint32_t i = 0; i < keyCount; i++)
	{
		mKeys.push_back(TKeyData() = { std::roundf(stream->readFloat() * SECONDS_TO_FRAMES), stream->readFloat()});
	}
} // TFunctionValueListParameter::LoadData

float JStudio::Engine::TFunctionValueListParameter::InterpolateNone()
{
	return 0.0f;
} // TFunctionValueListParameter::InterpolateNone

float JStudio::Engine::TFunctionValueListParameter::InterpolateLinear()
{
	return 0.0f;
} // TFunctionValueListParameter::InterpolateLinear

float JStudio::Engine::TFunctionValueListParameter::InterpolatePlateau()
{
	return 0.0f;
} // TFunctionValueListParameter::InterpolatePlateau

float JStudio::Engine::TFunctionValueListParameter::InterpolateBSpline()
{
	return 0.0f;
} // TFunctionValueListParameter::InterpolateBSpline
