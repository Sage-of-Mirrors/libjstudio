#pragma once

#include "types.h"

#include "functionvalue.hpp"
#include "rangeattribute.hpp"
#include "interpolateattribute.hpp"

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class TFunctionValueTransition : public TFunctionValue,
										 public IRangeAttribute,
										 public IInterpolateAttribute
		{
			float mValueA;
			float mValueB;

		public:
			TFunctionValueTransition() : mValueA(0.0f), mValueB(0.0f) { }
			virtual ~TFunctionValueTransition() { }

			TFunctionValueAttributeSet GetAttributeSet() override;
			float Evaluate(int32_t frame) override;

			void LoadData(bStream::CStream* stream) override;
		};
	} // namespace Engine
} // namespace JStudio
