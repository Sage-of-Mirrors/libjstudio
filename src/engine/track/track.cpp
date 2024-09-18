#include "engine/track/track.hpp"
#include "engine/track/meta.hpp"

#include <algorithm>
#include <vector>

void JStudio::Engine::TTrack::AddKey(const float& value, const uint32_t& time, const EUpdateType& updateType)
{
	mKeys.push_back(TKey{ value, time, 0, updateType });
	SortKeys();
}

void JStudio::Engine::TTrack::SortKeys()
{
	std::sort(mKeys.begin(), mKeys.end(), [](const TKey& a, const TKey& b) { return a.Time < b.Time; });
}

bool JStudio::Engine::TTrack::TryGetKey(const uint32_t& time, TKey& outKey)
{
	auto findResult = std::find_if(mKeys.begin(), mKeys.end(), [time](const TKey& a) { return a.Time == time; });
	if (findResult == mKeys.end())
	{
		return false;
	}

	outKey = *findResult;
	return true;
}

JStudio::Engine::TTrackMetadata JStudio::Engine::TTrack::GetMetadata()
{
	TTrackMetadata data = { "" };

	for (TKey& key : mKeys)
	{
		data.Keys.push_back((int32_t)key.Time);
	}

	return data;
}
