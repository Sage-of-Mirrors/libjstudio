#pragma once

#include "types.h"

namespace JStudio
{
	namespace Engine
	{
		class TFunctionValueRange
		{
			float mRangeStart;
			float mRangeEnd;

		public:
			TFunctionValueRange() : mRangeStart(0.0f), mRangeEnd(0.0f) { }
			virtual ~TFunctionValueRange() { }


		};
	} // namespace Engine
} // namespace JStudio

