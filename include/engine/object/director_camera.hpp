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
		class TDirectorCamera : public TDirector
		{
			static const uint32_t NUM_CAMERA_TRACKS = 10;

			TTrack mTracks[NUM_CAMERA_TRACKS] { };

		protected:
			void TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream) override;

		public:
			TDirectorCamera()
			{
				mNumTracks = NUM_CAMERA_TRACKS;
				mTracksHead = mTracks;
			}

			virtual ~TDirectorCamera() { }
		};
	} // namespace Engine
} // namespace JStudio
