#pragma once

#include "types.h"
#include "object.hpp"

#include "engine/value/variablevalue.hpp"

namespace JStudio
{
	namespace Engine
	{
		class TObjectCamera : public TObject
		{
			static const uint32_t NUM_CAMERA_VARIABLES = 10;

			TVariableValue mVariables[NUM_CAMERA_VARIABLES];

		public:
			TObjectCamera()
			{
				mNumVariables = NUM_CAMERA_VARIABLES;
				mVariablesHead = mVariables;
			}

			virtual ~TObjectCamera() { }

			void Update() override;
		};
	} // namespace Engine
} // namespace JStudio
