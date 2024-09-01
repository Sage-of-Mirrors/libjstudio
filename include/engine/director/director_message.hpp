#pragma once

#include "types.h"
#include "director.hpp"

#include "engine/track/track.hpp"
#include "engine/object/object_message.hpp"

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class TDirectorMessage : public TDirector
		{
			static const uint32_t NUM_MESSAGE_TRACKS = 1;

			TTrack mTracks[NUM_MESSAGE_TRACKS] { };

		protected:
			void TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream) override;

		public:
			TDirectorMessage()
			{
				mNumTracks = NUM_MESSAGE_TRACKS;
				mTracksHead = mTracks;
			}

			virtual ~TDirectorMessage() { }

			virtual TObject* CreateObject() override { return new TObjectMessage(); }
		};
	} // namespace Engine
} // namespace JStudio
