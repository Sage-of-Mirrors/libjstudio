#pragma once

#include "types.h"
#include "functionvalue.hpp"

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class TFunctionValueListParameter : public TFunctionValue
		{
			enum class EInterpolateType
			{
				NONE,
				LINEAR,
				PLATEAU,
				BSPLINE
			};

			EInterpolateType mInterpolateType;

			float InterpolateNone();
			float InterpolateLinear();
			float InterpolatePlateau();
			float InterpolateBSpline();

		public:
			TFunctionValueListParameter() : mInterpolateType(EInterpolateType::NONE) { }
			virtual ~TFunctionValueListParameter() { }

			float Evaluate(int32_t frame) override;

			bool Deserialize(bStream::CStream* stream) override;
			bool Serialize(bStream::CStream* stream) override;
		};
	} // namespace Engine
} // namespace JStudio
