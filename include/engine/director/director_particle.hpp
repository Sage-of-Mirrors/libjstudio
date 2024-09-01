#pragma once

#include "types.h"
#include "director.hpp"

#include "engine/track/track.hpp"
#include "engine/object/object_particle.hpp"

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

			virtual TObject* CreateObject() override { return new TObjectParticle(); }
		};
	} // namespace Engine
} // namespace JStudio
