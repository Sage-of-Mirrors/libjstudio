#include "engine/object/object.hpp"
#include "util.hpp"

#include <bstream.h>

constexpr uint8_t CONTROL_ID_WAIT = 0x02;
constexpr uint8_t CONTROL_ID_0x04 = 0x04;
constexpr uint8_t CONTROL_ID_PARAGRAPH = 0x80;

constexpr uint8_t BITMASK_UPDATE_TYPE = 0x1F;
constexpr uint8_t BITSHIFT_CMD_TYPE = 0x05;

bool JStudio::Engine::TObject::Deserialize(bStream::CStream* stream)
{
	mName = stream->readString(stream->readUInt32());
	if (stream->tell() % 4 != 0)
	{
		stream->seek(JStudio::Util::GetAlignedOffset(stream->tell(), 4));
	}

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
			stream->skip(4);
			break;
		case CONTROL_ID_PARAGRAPH:
			uint32_t paragraphSize = stream->readUInt32() & 0x00FFFFFF;

			uint32_t paragraphBytesRead = 0;
			while (paragraphBytesRead < paragraphSize)
			{
				uint16_t commandSize = stream->readUInt16();
				uint16_t commandBits = stream->readUInt16();
				paragraphBytesRead += commandSize + sizeof(uint16_t) + sizeof(uint16_t);

				TranslateCommand(curFrame, (uint16_t)(commandBits >> BITSHIFT_CMD_TYPE), (uint16_t)(commandBits & BITMASK_UPDATE_TYPE), stream);
			}

			break;
		}

		controlByte = stream->peekUInt8(stream->tell());
	}

	return true;
} //TObject::Deserialize()

bool JStudio::Engine::TObject::Serialize(bStream::CStream* stream)
{
	return true;
} // TObject::Serialize()
