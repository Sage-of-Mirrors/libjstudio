#include "engine/director/director_message.hpp"

#include <bstream.h>

// Command IDs
constexpr uint16_t CMD_MSG_ID = 0x0042;

// Track indices
constexpr int TRACK_MESSAGE_ID = 0x00;

void JStudio::Engine::TDirectorMessage::TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream)
{
	switch (cmdType)
	{
	case CMD_MSG_ID:
		mTracks[TRACK_MESSAGE_ID].AddKey((float)stream->readUInt32(), curFrame, EUpdateType::IMMEDIATE);
		break;
	}
}
