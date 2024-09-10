#pragma once

#include "types.h"

namespace JStudio
{
	namespace Engine
	{
		enum class EProgressType : uint8_t
		{
			POSITIVE,
			NEGATIVE,
			NEGATIVE_FROM_BEGIN,
			NEGATIVE_FROM_END,
			NEGATIVE_FROM_MIDDLE
		};

		enum class EAdjustType : uint8_t
		{
			NONE,
			BEGIN,
			END,
			MIDDLE,
			CONVERT
		};

		enum class EExtrapolateType : uint8_t
		{
			RAW,
			REPEAT,
			TURN,
			CLAMP
		};

		class IRangeAttribute
		{
		protected:
			float mRangeStart;
			float mRangeEnd;
			float mRangeWidth;
			EProgressType mProgressType;
			EAdjustType mAdjustType;

			float mProgressBase;
			float mProgressDirection;

			EExtrapolateType mUnderflowExtrapolation;
			EExtrapolateType mOverflowExtrapolation;

			float GetParameterProgress(float inValue) { return mProgressBase + mProgressDirection * (inValue - mProgressBase); }
			float GetParameterOutside(float value);

		public:
			IRangeAttribute() : mRangeStart(0.0f), mRangeEnd(0.0f), mRangeWidth(0.0f),
				mProgressType(EProgressType::POSITIVE), mAdjustType(EAdjustType::NONE), mProgressBase(0.0f), mProgressDirection(0.0f),
				mUnderflowExtrapolation(EExtrapolateType::RAW), mOverflowExtrapolation(EExtrapolateType::RAW) { }
			virtual ~IRangeAttribute() { }

			void PrepareRange();

			float GetParameter(float inValue, float newRangeStart, float newRangeEnd);

			void SetRange(float start, float end);
			void SetProgressType(EProgressType progress) { mProgressType = progress; PrepareRange(); }
			void SetAdjustType(EAdjustType adjust) { mAdjustType = adjust; }

			void SetUnderflowExtrapolationType(EExtrapolateType underflow) { mUnderflowExtrapolation = underflow; }
			void SetOverflowExtrapolationType(EExtrapolateType overflow) { mOverflowExtrapolation = overflow; }
			void SetExtrapolationTypes(EExtrapolateType under, EExtrapolateType over)
			{
				SetUnderflowExtrapolationType(under);
				SetOverflowExtrapolationType(over);
			}
		};
	} // namespace Engine
} // namespace JStudio

