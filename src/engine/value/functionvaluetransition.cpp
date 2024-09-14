#include "engine/value/functionvaluetransition.hpp"
#include "engine/value/interpolation.hpp"

#include <bstream.h>

JStudio::Engine::TFunctionValueAttributeSet JStudio::Engine::TFunctionValueTransition::GetAttributeSet()
{
	return TFunctionValueAttributeSet() = { nullptr, this, this };
} // TFunctionValueTransition::GetAttributeSet

float JStudio::Engine::TFunctionValueTransition::Evaluate(int32_t frame)
{
	PrepareRange();
	float sanitizedFrame = GetParameter((float)frame);
	float clampedValue = GetParameterOutside(sanitizedFrame);

	float result = 0.0f;
	switch (mAdjustType)
	{
	case EAdjustType::BEGIN:
	default:
		result = clampedValue < mRangeStart ? mValueA : mValueB;
		break;
	case EAdjustType::END:
		result = clampedValue < mRangeEnd ? mValueA : mValueB;
		break;
	case EAdjustType::MIDDLE:
		result = clampedValue < (mRangeStart + mRangeEnd) * 0.5f ? mValueA : mValueB;
		break;
	case EAdjustType::CONVERT:
		if (clampedValue < mRangeStart)
		{
			result = mValueA;
			break;
		}
		if (clampedValue >= mRangeEnd)
		{
			result = mValueB;
			break;
		}

		switch (mInterpolateType)
		{
		case EInterpolateType::NONE:
		default:
			result = clampedValue < (mRangeStart + mRangeEnd) * 0.5f ? mValueA : mValueB;
			break;
		case EInterpolateType::LINEAR:
		case EInterpolateType::BSPLINE:
			result = mValueA + ((clampedValue - mRangeStart) * (mValueB - mValueA)) / mRangeWidth;
			break;
		case EInterpolateType::PLATEAU:
			result = Engine::InterpolatePlateau(clampedValue, mRangeStart, mValueA, mRangeEnd, mValueB);
			break;
		}

		break;
	}

	return result;
} // TFunctionValueTransition::Evaluate

void JStudio::Engine::TFunctionValueTransition::LoadData(bStream::CStream* stream)
{
	mValueA = stream->readFloat();
	mValueB = stream->readFloat();
} // TFunctionValueTransition::LoadData
