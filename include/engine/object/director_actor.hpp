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
		class TDirectorActor : public TDirector
		{
			static const uint32_t NUM_ACTOR_TRACKS = 9;

			TTrack mTracks[NUM_ACTOR_TRACKS] { };

		protected:
			void TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream) override;

		public:
			TDirectorActor()
			{
				mNumTracks = NUM_ACTOR_TRACKS;
				mTracksHead = mTracks;
			}

			virtual ~TDirectorActor() { }
		};
	} // namespace Engine
} // namespace JStudio
