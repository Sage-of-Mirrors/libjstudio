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

		class IInterpolateAttribute
		{
		protected:
			EInterpolateType mInterpolateType;

		public:
			IInterpolateAttribute() : mInterpolateType(EInterpolateType::NONE) { }
			virtual ~IInterpolateAttribute() { }

			void SetInterpolateType(EInterpolateType interpolate) { mInterpolateType = interpolate; }
		};
	} // namespace Engine
} // namespace JStudio
