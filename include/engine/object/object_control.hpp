#pragma once

#include "types.h"
#include "object.hpp"

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class TObjectControl : public TObject
		{
		protected:
			void TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream) override;

		public:
			TObjectControl() { }
			virtual ~TObjectControl() { }
		};
	}
}