#pragma once

#include "types.h"
#include "director.hpp"

#include "engine/track/track.hpp"

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class TDirectorParticle : public TDirector
		{
		protected:
			void TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream) override;

		public:
			TDirectorParticle() { }
			virtual ~TDirectorParticle() { }
		};
	} // namespace Engine
} // namespace JStudio
