#include "engine/value/functionvaluehermite.hpp"
#include "engine/value/interpolation.hpp"

#include <bstream.h>

constexpr float SECONDS_TO_FRAMES = 30.0f;
constexpr float FRAMES_TO_SECONDS = 1.0f / 30.0f;

JStudio::Engine::TFunctionValueAttributeSet JStudio::Engine::TFunctionValueHermite::GetAttributeSet()
{
	return TFunctionValueAttributeSet() = { nullptr, this, nullptr };
} // TFunctionValueHermite::GetAttributeSet

float JStudio::Engine::TFunctionValueHermite::Evaluate(int32_t frame)
{
	PrepareRange();
	float sanitizedFrame = GetParameter((float)frame, mKeys.front().Time, mKeys.back().Time);

	auto curKey = std::find_if
	(
		mKeys.begin(),
		mKeys.end(),
		[sanitizedFrame](const TKeyData& data) { return sanitizedFrame < data.Time; }
	);

	if (curKey == mKeys.begin())
	{
		return mKeys.front().Value;
	}
	else if (curKey == mKeys.end())
	{
		return mKeys.back().Value;
	}

	std::vector<TKeyData>::iterator lastKey = curKey - 1;

	return Engine::InterpolateHermite
	(
		sanitizedFrame,
		(*lastKey).Time, (*lastKey).Value, (*lastKey).OutTangent,
		(*curKey).Time, (*curKey).Value, (*curKey).InTangent
	);
} // TFunctionValueHermite::Evaluate

void JStudio::Engine::TFunctionValueHermite::LoadData(bStream::CStream* stream)
{
	uint32_t bitfield = stream->readUInt32();
	uint32_t keySize = bitfield >> 0x1C;

	assert(keySize == 0x03 || keySize == 0x04);

	uint32_t keyCount = bitfield & 0x0FFFFFFF;

	for (uint32_t i = 0; i < keyCount; i++)
	{
		TKeyData newKey =
		{
			std::roundf(stream->readFloat() * SECONDS_TO_FRAMES),
			stream->readFloat(),
			stream->readFloat(),
			0.0f
		};


		if (keySize == 4)
		{
			newKey.OutTangent = stream->readFloat();
		}
		else
		{
			newKey.OutTangent = newKey.InTangent;
		}

		mKeys.push_back(newKey);
	}

} // TFunctionValueHermite::LoadData
