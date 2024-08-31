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
		class TTrack;

		class TDirector
		{
		protected:
			std::string mName;

			uint32_t mNumTracks;
			TTrack* mTracksHead;

			virtual void TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream) = 0;

		public:
			TDirector()
			{
				mNumTracks = 0;
				mTracksHead = nullptr;
			}

			virtual ~TDirector() { }

			virtual bool Deserialize(bStream::CStream* stream);
			virtual bool Serialize(bStream::CStream* stream);

			TTrack* GetTrack(uint32_t trackIndex);
		};
	} // namespace Engine
} // namespace JStudio
