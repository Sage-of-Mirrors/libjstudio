#pragma once

#include "types.h"

namespace JStudio
{
	namespace Engine
	{
		enum class EVariableUpdateType
		{
			NONE,
			LINEAR,
			FUNCTION_VALUE
		};

		class TVariableValue
		{
			float mValue;

			EVariableUpdateType mUpdateType;
			uint32_t mFrameCount;

			union
			{
				float mUpdateRate;
				uint32_t mFunctionValueIndex;
			};

		public:
			TVariableValue() : mValue(0.0f), mFrameCount(0), mUpdateType(EVariableUpdateType::NONE) { }
			virtual ~TVariableValue() { }

			float GetValue() const;

			void Update(float deltaTime);
			void Reset();

			void SetImmediateUpdate(float value);
			void SetLinearUpdate(float updateRate);
			void SetFunctionValueUpdate(uint32_t funcValIdx);
		};
	} // namespace Engine
} // namespace JStudio
