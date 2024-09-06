#pragma once

#include "types.h"

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class TFunctionValue
		{
		public:
			TFunctionValue() { }
			virtual ~TFunctionValue() { }

			virtual bool Deserialize(bStream::CStream* stream) = 0;
			virtual bool Serialize(bStream::CStream* stream) = 0;
		};
	} // namespace Engine
} // namespace JStudio
