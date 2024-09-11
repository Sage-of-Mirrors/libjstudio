#include "engine/object/object.hpp"
#include "engine/value/variablevalue.hpp"
#include "engine/director/director.hpp"
#include "engine/track/track.hpp"
#include "engine/enginedata.hpp"

void JStudio::Engine::TObject::UpdateVariables(TDirector* director, const uint32_t& frame, const float& deltaTime)
{
	if (mVariablesHead == nullptr || director == nullptr)
	{
		return;
	}

	for (uint32_t i = 0; i < mNumVariables; i++)
	{
		TTrack* track = director->GetTrack(i);
		if (track != nullptr)
		{
			TKey key;
			if (track->TryGetKey(frame, key))
			{
				switch (key.Type)
				{
				case EUpdateType::IMMEDIATE:
					mVariablesHead[i].SetImmediateUpdate(key.Value);
					break;
				case EUpdateType::TIME:
					mVariablesHead[i].SetLinearUpdate(key.Value);
					break;
				case EUpdateType::FUNCVALUE_INDEX:
					mVariablesHead[i].SetFunctionValueUpdate((uint32_t)key.Value);
					break;
				case EUpdateType::NONE:
				default:
					mVariablesHead[i].SetImmediateUpdate(key.Value);
					break;
				}
			}
		}

		mVariablesHead[i].Update(deltaTime);
	}
} // TObject::UpdateVariables
