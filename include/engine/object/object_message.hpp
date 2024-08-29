#pragma once

#include "types.h"
#include "object.hpp"

#include "engine/track/track.hpp"

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class TObjectMessage : public TObject
		{
			TTrack<uint32_t> mMessageTrack;

		protected:
			void TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream) override;

		public:
			TObjectMessage() { }
			virtual ~TObjectMessage() { }
		};
	}
}
