#include "engine/value/interpolation.hpp"

#include <cmath>

constexpr float ONE_SIXTH = 1.0f / 6.0f;
constexpr float TWO_THIRDS = 2.0f / 3.0f;

float JStudio::Engine::InterpolateHermite(float factor, float timeA, float valueA, float outTangent, float timeB, float valueB, float inTangent)
{
	float a = factor - timeA;
	float b = a * (1.0f / (timeB - timeA));
	float c = b - 1.0f;
	float d = (3.0f + -2.0f * b) * (b * b);

	float cab = c * a * b;
	float coeffx3 = cab * inTangent;
	float cca = c * c * a;
	float coeffc2 = cca * outTangent;

	return b * c * a * inTangent + a * c * c * outTangent + (1.0f - d) * valueA + d * valueB;
} // InterpolateHermite

float JStudio::Engine::InterpolateBSplineUniform(float factor, float p2, float p3, float p4, float p5)
{
	float invFactorCubed = std::powf(1.0f - factor, 3.0f);
	float factorSquared = factor * factor;
	float factorCubed = factorSquared * factor;

	float temp2 = (ONE_SIXTH + 0.5f * ((factor + factorSquared) - factorCubed));
	float temp3 = temp2 * p4;

	float temp4 = (0.5f * factorCubed - factorSquared) + TWO_THIRDS;
	float temp5 = temp4 * p3;

	return temp5 + (invFactorCubed * p2 + factorCubed * p5) * ONE_SIXTH + temp3;
} // InterpolateBSplineUniform

float JStudio::Engine::InterpolateBSplineNonuniform(float factor, std::vector<float>& controlPoints, std::vector<float>& knots)
{
	float diffs[6]
	{
		factor - knots[0],
		factor - knots[1],
		factor - knots[2],
		knots[3] - factor,
		knots[4] - factor,
		knots[5] - factor
	};

	float invDeltaKnot3_2 = 1.0f / (knots[3] - knots[2]);

	float blendFactor3 = (diffs[3] * invDeltaKnot3_2) / (knots[3] - knots[1]);
	float blendFactor2 = (diffs[2] * invDeltaKnot3_2) / (knots[4] - knots[2]);
	float blendFactor1 = (diffs[3] * blendFactor3) / (knots[3] - knots[0]);
	float blendFactor4 = ((diffs[1] * blendFactor3) + (diffs[4] * blendFactor2)) / (knots[4] - knots[1]);
	float blendFactor5 = (diffs[2] * blendFactor2) / (knots[5] - knots[2]);

	float term1 = diffs[3] * blendFactor1;
	float term2 = (diffs[0] * blendFactor1) + (diffs[4] * blendFactor4);
	float term3 = (diffs[1] * blendFactor4) + (diffs[5] * blendFactor5);
	float term4 = diffs[2] * blendFactor5;

	return (term1 * controlPoints[0]) + (term2 * controlPoints[1]) + (term3 * controlPoints[2]) + (term4 * controlPoints[3]);
} // InterpolateBSplineNonuniform

float JStudio::Engine::InterpolateLinear(float factor, float timeA, float valueA, float timeB, float valueB)
{
	return valueA + ((valueB - valueA) * (factor - timeA)) / (timeB - timeA);
} // InterpolateLinear

float JStudio::Engine::InterpolateLinear_1(float factor, float time, float valueA, float valueB)
{
	return valueA + (valueB - valueA) * (factor - time);
} // InterpolateLinear_1

float JStudio::Engine::InterpolatePlateau(float p1, float p2, float p3, float p4, float p5)
{
	return InterpolateHermite(p1, p2, p3, 0.0f, p4, p5, 0.0f);
} // InterpolatePlateau
