#pragma once

#include "types.h"

namespace JStudio
{
	namespace Engine
	{
		template<typename T>
		class TKey
		{
			T mValue;
			uint32_t mTime;

		public:
			TKey(T init, uint32_t time) : mValue(init), mTime(time) { }
			virtual ~TKey() { }

			T GetValue() const { return mValue; }
			void SetValue(const T& value) { mValue = value; }

			uint32_t GetTime() const { return mTime; }
			void SetTime(const uint32_t& time) { mTime = time; }
		};
	} // namespace Engine
} // namespace JStudio
