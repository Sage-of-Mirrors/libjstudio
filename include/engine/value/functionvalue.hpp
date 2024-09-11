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
		public:
			TFunctionValue() { }
			virtual ~TFunctionValue() { }

			virtual TFunctionValueAttributeSet GetAttributeSet() = 0;
			virtual float Evaluate(int32_t frame) = 0;

			virtual void LoadData(bStream::CStream* stream) = 0;
		};
	} // namespace Engine
} // namespace JStudio
