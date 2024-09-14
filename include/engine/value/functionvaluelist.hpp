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
		class TFunctionValueList : public TFunctionValue,
								   public IRangeAttribute,
								   public IInterpolateAttribute
		{
		public:
			TFunctionValueList() { }
			virtual ~TFunctionValueList() { }

			TFunctionValueAttributeSet GetAttributeSet() override;
			float Evaluate(int32_t frame) override;

			void LoadData(bStream::CStream* stream) override;
		};
	} // namespace Engine
} // namespace JStudio
