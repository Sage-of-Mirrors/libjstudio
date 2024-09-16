#pragma once

#include "types.h"
#include "object.hpp"

#include "engine/value/variablevalue.hpp"

namespace JStudio
{
	namespace Engine
	{
		class TObjectControl : public TObject
		{
			static const uint32_t NUM_CONTROL_VARIABLES = 1;

			TVariableValue mVariables[NUM_CONTROL_VARIABLES];

		public:
			TObjectControl()
			{
				mNumVariables = NUM_CONTROL_VARIABLES;
				mVariablesHead = mVariables;

				mType = EObjectType::CONTROL;
			}

			virtual ~TObjectControl() { }

			void Update() override;

			bool GetMessageHalt();
			void ClearMessageHalt();
		};
	} // namespace Engine
} // namespace JStudio
