#pragma once

#include "types.h"
#include "director.hpp"

#include "engine/track/track.hpp"
#include "engine/object/object_sound.hpp"

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class TDirectorSound : public TDirector
		{
			static const uint32_t NUM_SOUND_TRACKS = 3;

			TTrack mTracks[NUM_SOUND_TRACKS] { };

		protected:
			void TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream) override;

		public:
			TDirectorSound()
			{
				mNumTracks = NUM_SOUND_TRACKS;
				mTracksHead = mTracks;
			}

			virtual ~TDirectorSound() { }

			virtual TObject* CreateObject() override { return new TObjectSound(); }
		};
	} // namespace Engine
} // namespace JStudio
