#include "engine/value/functionvaluerange.hpp"
#include "engine/value/extrapolation.hpp"

void JStudio::Engine::TFunctionValueRange::SetRange(float start, float end)
{
	mRangeStart = start;
	mRangeEnd = end;
	mRangeWidth = end - start;
} // TFunctionValueRange::SetRange

void JStudio::Engine::TFunctionValueRange::PrepareRange()
{
	switch (mProgressType)
	{
	case EProgressType::POSITIVE:
		mProgressBase = 0.0f;
		mProgressDirection = 1.0f;
		break;
	case EProgressType::NEGATIVE:
		mProgressBase = 0.0f;
		mProgressDirection = -1.0f;
		break;
	case EProgressType::NEGATIVE_FROM_BEGIN:
		mProgressBase = mRangeStart;
		mProgressDirection = -1.0f;
		break;
	case EProgressType::NEGATIVE_FROM_END:
		mProgressBase = mRangeEnd;
		mProgressDirection = -1.0f;
		break;
	case EProgressType::NEGATIVE_FROM_MIDDLE:
		mProgressBase = 0.5f * (mRangeStart + mRangeEnd);
		mProgressDirection = -1.0f;
		break;
	}
} // TFunctionValueRange::SetRange

float JStudio::Engine::TFunctionValueRange::GetParameter(float inValue, float newRangeStart, float newRangeEnd)
{
	float progress = GetParameterProgress(inValue);
	float result = 0.0f;

	switch (mAdjustType)
	{
	case EAdjustType::NONE:
		result = GetParameterOutside(progress);
		break;
	case EAdjustType::BEGIN:
		result = GetParameterOutside(progress + mRangeStart);
		break;
	case EAdjustType::END:
		result = GetParameterOutside(progress + mRangeEnd);
		break;
	case EAdjustType::MIDDLE:
		result = GetParameterOutside(progress + 0.5f * (mRangeStart + mRangeEnd));
		break;
	case EAdjustType::CONVERT:
		result = GetParameterOutside(progress);
		result = newRangeStart + ((result - mRangeStart) * (newRangeEnd - newRangeStart)) / mRangeWidth;
		break;
	}

	return result;
} // TFunctionValueRange::GetParameter

float JStudio::Engine::TFunctionValueRange::GetParameterOutside(float value)
{
	float result = value - mRangeStart;
	EExtrapolateType extrapolation = EExtrapolateType::RAW;

	if (result < 0.0f)
	{
		extrapolation = mUnderflowExtrapolation;
	}
	else if (result >= mRangeWidth)
	{
		extrapolation = mOverflowExtrapolation;
	}

	switch (extrapolation)
	{
	case EExtrapolateType::RAW:
		// Do nothing
		break;
	case EExtrapolateType::REPEAT:
		result = ExtrapolateRepeat(value, mRangeWidth);
		break;
	case EExtrapolateType::TURN:
		result = ExtrapolateTurn(value, mRangeWidth);
		break;
	case EExtrapolateType::CLAMP:
		result = ExtrapolateClamp(value, mRangeWidth);
		break;
	}

	return result + mRangeStart;
} // TFunctionValueRange::GetParameterOutside
