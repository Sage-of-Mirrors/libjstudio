#pragma once

#include "types.h"
#include "functionvalue.hpp"
#include "rangeattribute.hpp"
#include "interpolateattribute.hpp"

#include <vector>

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class TFunctionValueListParameter : public TFunctionValue,
											public IRangeAttribute,
											public IInterpolateAttribute
		{
			struct TKeyData
			{
				float Time;
				float Value;
			};

			std::vector<TKeyData> mKeys;

			float InterpolateNone();
			float InterpolateLinear();
			float InterpolatePlateau();
			float InterpolateBSpline();

		public:
			TFunctionValueListParameter() { }
			virtual ~TFunctionValueListParameter() { }

			TFunctionValueAttributeSet GetAttributeSet() override;
			float Evaluate(int32_t frame) override;

			void LoadData(bStream::CStream* stream) override;
		};
	} // namespace Engine
} // namespace JStudio
