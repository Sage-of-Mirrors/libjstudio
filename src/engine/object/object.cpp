#include "engine/object/object.hpp"
#include "engine/object/variablevalue.hpp"
#include "engine/director/director.hpp"
#include "engine/track/track.hpp"

void JStudio::Engine::TObject::UpdateVariables(TDirector* director, const uint32_t& frame, const float& deltaTime)
{
	if (mVariablesHead == nullptr || director == nullptr)
	{
		return;
	}

	for (uint32_t i = 0; i < mNumVariables; i++)
	{
		if (mVariablesHead[i].GetUpdateByFrameCount())
		{
			float updatedValue = (float)mVariablesHead[i].GetFrameCount() * mVariablesHead[i].GetUpdateRate() * deltaTime;
			mVariablesHead[i].SetValue(updatedValue);

			mVariablesHead[i].IncrementFrameCount();
		}

		TTrack* track = director->GetTrack(i);
		if (track != nullptr)
		{
			TKey key;
			if (track->TryGetKey(frame, key))
			{
				switch (key.Type)
				{
				case EUpdateType::IMMEDIATE:
					mVariablesHead[i].SetValue(key.Value);
					mVariablesHead[i].SetUpdateByFrameCount(false);
					break;
				case EUpdateType::TIME:
					mVariablesHead[i].SetUpdateByFrameCount(true);
					mVariablesHead[i].SetUpdateRate(key.Value);
					break;
				case EUpdateType::FUNCVALUE_INDEX:
					break;
				case EUpdateType::NONE:
				default:
					break;
				}
			}
		}
	}
}
