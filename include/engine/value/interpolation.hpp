#pragma once

#include "types.h"

#include <vector>

namespace JStudio
{
	namespace Engine
	{
		float InterpolateHermite(float p1, float p2, float p3, float p4, float p5, float p6, float p7);
		float InterpolateBSplineUniform(float p1, float p2, float p3, float p4, float p5);
		float InterpolateBSplineNonuniform(float p1, std::vector<float>& controlPoints, std::vector<float>& knots);
		float InterpolateLinear(float factor, float timeA, float valueA, float timeB, float valueB);
		float InterpolateLinear_1(float p1, float p2, float p3, float p4);
		float InterpolatePlateau(float p1, float p2, float p3, float p4, float p5);
	} // namespace Engine
} // namespace JStudio
