#pragma once

#include "types.h"

#include <vector>

namespace JStudio
{
	namespace Engine
	{
		class TVariableValue;
		class TDirector;

		class TObject
		{
		protected:
			uint32_t mNumVariables;
			TVariableValue* mVariablesHead;

		public:
			TObject()
			{
				mNumVariables = 0;
				mVariablesHead = nullptr;
			}

			virtual ~TObject() { }

			virtual void UpdateVariables(TDirector* director, const uint32_t& frame, const float& deltaTime);
			virtual void Update() { }
		};
	} // namespace Engine
} // namespace JStudio
