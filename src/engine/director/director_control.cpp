#include "engine/director/director_control.hpp"
#include "util.hpp"

#include <bstream.h>

#include <iostream>

constexpr uint8_t CONTROL_ID_WAIT = 0x02;
constexpr uint8_t CONTROL_ID_0x04 = 0x04;
constexpr uint8_t CONTROL_ID_PARAGRAPH = 0x80;

// Track indices
constexpr int TRACK_MESSAGE_HALT = 0x00;

void JStudio::Engine::TDirectorControl::TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream)
{

} // TDirectorControl::TranslateCommand

bool JStudio::Engine::TDirectorControl::Deserialize(bStream::CStream* stream, uint32_t& demoLength)
{
	mName = stream->readString(stream->readUInt32());
	stream->seek(JStudio::Util::GetNextAligned(stream->tell(), 4));

	uint32_t curFrame = 0;

	uint8_t controlByte = stream->peekUInt8(stream->tell());
	while (controlByte != 0)
	{
		switch (controlByte)
		{
		case CONTROL_ID_WAIT:
			curFrame += stream->readUInt32() & 0x00FFFFFF;
			break;
		case CONTROL_ID_0x04:
			mTracks[TRACK_MESSAGE_HALT].AddKey(1.0f, curFrame, EUpdateType::IMMEDIATE);
			stream->skip(4);
			break;
		case CONTROL_ID_PARAGRAPH:
			std::cout << "TDirectorControl: Control director should never find paragraphs!" << std::endl;
			assert(false);
			break;
		}

		controlByte = stream->peekUInt8(stream->tell());
	}

	if (curFrame >= demoLength)
	{
		demoLength = curFrame;
	}

	return true;
} // TDirectorControl::Deserialize
