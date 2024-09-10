#pragma once

#include "types.h"

namespace JStudio
{
	namespace Engine
	{
		enum class EInterpolateType : uint8_t
		{
			NONE,
			LINEAR,
			PLATEAU,
			BSPLINE
		};

		class TFunctionValueAttribute_Interpolate
		{
		protected:
			EInterpolateType mInterpolateType;

		public:
			TFunctionValueAttribute_Interpolate() : mInterpolateType(EInterpolateType::NONE) { }
			virtual ~TFunctionValueAttribute_Interpolate() { }

			void SetInterpolateType(EInterpolateType interpolate) { mInterpolateType = interpolate; }
		};
	} // namespace Engine
} // namespace JStudio
