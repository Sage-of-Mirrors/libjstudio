#pragma once

#include "types.h"

namespace JStudio
{
	namespace Engine
	{
		class TVariableValue
		{
			float mValue;

			bool bUpdateValueByFrameCount;
			uint32_t mFrameCount;
			float mUpdateRate;

		public:
			TVariableValue() : mValue(0.0f), mFrameCount(0), bUpdateValueByFrameCount(false), mUpdateRate(0.0f) { }
			virtual ~TVariableValue() { }

			float GetValue() const;
			void SetValue(float value);

			bool GetUpdateByFrameCount() const;
			void SetUpdateByFrameCount(bool update);

			uint32_t GetFrameCount() const;
			void IncrementFrameCount();
			void ResetFrameCount();

			float GetUpdateRate() const;
			void SetUpdateRate(float value);
		};
	} // namespace Engine
} // namespace JStudio
