#pragma once

#include "types.h"

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class IReferAttribute;
		class IRangeAttribute;
		class IInterpolateAttribute;

		struct TFunctionValueAttributeSet
		{
			IReferAttribute* Refer;
			IRangeAttribute* Range;
			IInterpolateAttribute* Interpolate;
		};

		class TFunctionValue
		{
		protected:
			float* mData;
			uint32_t mDataCount;

		public:
			TFunctionValue() : mData(nullptr), mDataCount(0) { }
			virtual ~TFunctionValue() { }

			virtual TFunctionValueAttributeSet GetAttributeSet() = 0;
			virtual float Evaluate(int32_t frame) = 0;

			virtual bool Deserialize(bStream::CStream* stream) = 0;
			virtual bool Serialize(bStream::CStream* stream) = 0;
		};
	} // namespace Engine
} // namespace JStudio
