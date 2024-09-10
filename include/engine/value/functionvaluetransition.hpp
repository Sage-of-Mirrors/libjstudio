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
		class TFunctionValueTransition : public TFunctionValue
		{
		public:
			TFunctionValueTransition() { }
			virtual ~TFunctionValueTransition() { }

			TFunctionValueAttributeSet GetAttributeSet() override;
			float Evaluate(int32_t frame) override;

			bool Deserialize(bStream::CStream* stream) override;
			bool Serialize(bStream::CStream* stream) override;
		};
	} // namespace Engine
} // namespace JStudio
