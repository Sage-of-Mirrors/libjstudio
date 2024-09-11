#include "engine/value/functionvaluelistparameter.hpp"
#include "engine/value/interpolation.hpp"
#include "util.hpp"

#include <bstream.h>
#include <cmath>
#include <algorithm>

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
	PrepareRange();
	float sanitizedFrame = GetParameter((float)frame, mKeys.front().Time, mKeys.back().Time);

	auto curKeyItr = std::find_if
	(
		mKeys.begin(),
		mKeys.end(),
		[sanitizedFrame](const TKeyData& data) { return sanitizedFrame < data.Time; }
	);

	if (curKeyItr == mKeys.end())
	{
		return mKeys.back().Value;
	}

	float result = 0.0f;

	switch (mInterpolateType)
	{
	case EInterpolateType::NONE:
		result = InterpolateNone(sanitizedFrame, curKeyItr);
		break;
	case EInterpolateType::LINEAR:
		result = InterpolateLinear(sanitizedFrame, curKeyItr);
		break;
	case EInterpolateType::PLATEAU:
		result = InterpolatePlateau(sanitizedFrame, curKeyItr);
		break;
	case EInterpolateType::BSPLINE:
		result = InterpolateBSpline(sanitizedFrame, curKeyItr);
		break;
	}

	return result;
} // TFunctionValueListParameter::Evaluate

void JStudio::Engine::TFunctionValueListParameter::LoadData(bStream::CStream* stream)
{
	uint32_t keyCount = stream->readUInt32();

	for (uint32_t i = 0; i < keyCount; i++)
	{
		mKeys.push_back(TKeyData() = { std::roundf(stream->readFloat() * SECONDS_TO_FRAMES), stream->readFloat()});
	}
} // TFunctionValueListParameter::LoadData

float JStudio::Engine::TFunctionValueListParameter::InterpolateNone(float time, std::vector<TKeyData>::iterator curKey)
{
	std::vector<TKeyData>::iterator lastKey = curKey - 1;
	return (*lastKey).Value;
} // TFunctionValueListParameter::InterpolateNone

float JStudio::Engine::TFunctionValueListParameter::InterpolateLinear(float time, std::vector<TKeyData>::iterator curKey)
{
	std::vector<TKeyData>::iterator lastKey = curKey - 1;
	return Engine::InterpolateLinear(time, (*lastKey).Time, (*lastKey).Value, (*curKey).Time, (*curKey).Value);
} // TFunctionValueListParameter::InterpolateLinear

float JStudio::Engine::TFunctionValueListParameter::InterpolatePlateau(float time, std::vector<TKeyData>::iterator curKey)
{
	std::vector<TKeyData>::iterator lastKey = curKey - 1;
	return Engine::InterpolatePlateau(time, (*lastKey).Time, (*lastKey).Value, (*curKey).Time, (*curKey).Value);
} // TFunctionValueListParameter::InterpolatePlateau

float JStudio::Engine::TFunctionValueListParameter::InterpolateBSpline(float time, std::vector<TKeyData>::iterator curKey)
{
	std::vector<float> controlPoints(4);
	std::vector<float> knots(6);

	std::vector<TKeyData>::iterator lastKey = curKey - 1;
	std::vector<TKeyData>::iterator nextKey = curKey + 1;

	// 90% of this code is copied from https://github.com/zeldaret/tww/blob/main/src/JSystem/JStudio/JStudio/functionvalue.cpp#L765.
	// I don't have a full understanding of what all of it means.

	controlPoints[1] = (*lastKey).Value;
	controlPoints[2] = (*curKey).Value;
	knots[2] = (*lastKey).Time;
	knots[3] = (*curKey).Time;

	int32_t distToEnd = (int32_t)std::distance(curKey, mKeys.end()) * 2;
	int32_t distToBegin = (int32_t)std::distance(mKeys.begin(), curKey) * 2;

	switch (distToBegin)
	{
	case 2:
		controlPoints[0] = 2.0f * controlPoints[1] - controlPoints[2];
		controlPoints[3] = (*nextKey).Value;

		knots[4] = (*nextKey).Time;
		knots[1] = 2.0f * knots[2] - knots[3];
		knots[0] = 2.0f * knots[2] - knots[4];

		switch (distToEnd)
		{
		case 2:
		case 4:
			knots[5] = 2.0f * knots[4] - knots[3];
			break;
		default:
			knots[5] = (*(curKey + 2)).Time;
			break;
		}
		break;
	case 4:
		controlPoints[0] = (*(curKey - 2)).Value;

		knots[1] = (*(curKey - 2)).Time;
		knots[0] = 2.0f * knots[1] - knots[2];

		switch (distToEnd)
		{
		case 2:
			controlPoints[3] = 2.0f * controlPoints[2] - controlPoints[1];

			knots[4] = 2.0f * knots[3] - knots[2];
			knots[5] = 2.0f * knots[3] - knots[1];

			break;
		case 4:
			controlPoints[3] = (*nextKey).Value;

			knots[4] = (*nextKey).Time;
			knots[5] = 2.0f * knots[4] - knots[3];

			break;
		default:
			controlPoints[3] = (*nextKey).Value;

			knots[4] = (*nextKey).Time;
			knots[5] = (*(curKey + 2)).Time;

			break;
		}
		break;
	default:
		controlPoints[0] = (*(curKey - 2)).Value;

		knots[1] = (*(curKey - 2)).Time;
		knots[0] = (*(curKey - 3)).Time;

		switch (distToEnd)
		{
		case 2:
			controlPoints[3] = 2.0f * controlPoints[2] - controlPoints[1];

			knots[4] = 2.0f * knots[3] - knots[2];
			knots[5] = 2.0f * knots[3] - knots[1];

			break;
		case 4:
			controlPoints[3] = (*nextKey).Value;
			
			knots[4] = (*nextKey).Time;
			knots[5] = 2.0f * knots[4] - knots[3];

			break;
		default:
			controlPoints[3] = (*nextKey).Value;
			
			knots[4] = (*nextKey).Time;
			knots[5] = (*(curKey + 2)).Time;

			break;
		}
		break;
	}

	return Engine::InterpolateBSplineNonuniform(time, controlPoints, knots);
} // TFunctionValueListParameter::InterpolateBSpline
