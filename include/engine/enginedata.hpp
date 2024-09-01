#pragma once

#include "types.h"

#include <vector>

namespace JStudio
{
	namespace Engine
	{
		class TFunctionValue;

		class TEngineData
		{
			bool bHaltForInput;
			uint32_t mCurrentMessageId;

			std::vector<TFunctionValue*> mFunctionValues;

		public:
			TEngineData() : bHaltForInput(false), mCurrentMessageId(0) { }
			virtual ~TEngineData();

			bool GetHaltForInput() const { return bHaltForInput; }
			void SetHaltForInput(bool halt) { bHaltForInput = halt; }

			uint32_t GetCurrentMessageId() const { return mCurrentMessageId; }
			void SetCurrentMessageId(uint32_t id) { mCurrentMessageId = id; }

			std::vector<TFunctionValue*>& GetFunctionValues() { return mFunctionValues; }
			void SetFunctionValues(std::vector<TFunctionValue*>& values) { mFunctionValues = values; }
		};
	} // namespace Engine
} // namespace JStudio
