#pragma once

#include "types.h"
#include "functionvalue.hpp"
#include "rangeattribute.hpp"

#include <vector>

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class TFunctionValueHermite : public TFunctionValue,
									  public IRangeAttribute
		{
			struct TKeyData
			{
				float Time;
				float Value;
				float InTangent;
				float OutTangent;
			};

			std::vector<TKeyData> mKeys;

		public:
			TFunctionValueHermite() { }
			virtual ~TFunctionValueHermite() { }

			TFunctionValueAttributeSet GetAttributeSet() override;
			float Evaluate(int32_t frame) override;

			void LoadData(bStream::CStream* stream) override;
		};
	} // namespace Engine
} // namespace JStudio
