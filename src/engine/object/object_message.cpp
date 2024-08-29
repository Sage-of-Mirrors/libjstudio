#include "engine/object/object_message.hpp"

#include <bstream.h>

constexpr uint16_t CMD_MSG_ID = 0x0042;

void JStudio::Engine::TObjectMessage::TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream)
{
	switch (cmdType)
	{
	case CMD_MSG_ID:
		mMessageTrack.AddKey(stream->readUInt32(), curFrame);
		break;
	}
}
