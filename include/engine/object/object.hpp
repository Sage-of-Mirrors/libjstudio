#pragma once

#include "types.h"

#include <vector>

namespace JStudio
{
	namespace Engine
	{
		class TVariableValue;
		class TDirector;

		enum class EObjectType
		{
			NONE,
			CAMERA,
			ACTOR,
			MESSAGE,
			CONTROL,
			PARTICLE,
			SOUND
		};

		class TObject
		{
		protected:
			uint32_t mNumVariables;
			TVariableValue* mVariablesHead;

			EObjectType mType;

		public:
			TObject()
			{
				mNumVariables = 0;
				mVariablesHead = nullptr;

				mType = EObjectType::NONE;
			}

			virtual ~TObject() { }

			EObjectType GetObjectType() const { return mType; }

			virtual void UpdateVariables(TDirector* director, const uint32_t& frame, const float& deltaTime);
			virtual void Update() { }
		};
	} // namespace Engine
} // namespace JStudio
