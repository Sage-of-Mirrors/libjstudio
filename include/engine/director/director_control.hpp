#pragma once

#include "types.h"
#include "director.hpp"

#include "engine/track/track.hpp"
#include "engine/object/object_control.hpp"

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class TDirectorControl : public TDirector
		{
			static const uint32_t NUM_CONTROL_TRACKS = 1;

			TTrack mTracks[NUM_CONTROL_TRACKS] { };

		protected:
			void TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream) override;

		public:
			TDirectorControl()
			{
				mNumTracks = NUM_CONTROL_TRACKS;
				mTracksHead = mTracks;
			}

			virtual ~TDirectorControl() { }

			virtual TObject* CreateObject() override { return new TObjectControl(); }

			bool Deserialize(bStream::CStream* stream, uint32_t& demoLength) override;
		};
	} // namespace Engine
} // namespace JStudio
