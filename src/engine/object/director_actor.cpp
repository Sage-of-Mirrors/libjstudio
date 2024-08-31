#include "engine/object/director_actor.hpp"

#include <bstream.h>

// Command IDs
constexpr uint16_t CMD_SET_X_POS   = 0x0009;
constexpr uint16_t CMD_SET_Y_POS   = 0x000A;
constexpr uint16_t CMD_SET_Z_POS   = 0x000B;
constexpr uint16_t CMD_SET_POS     = 0x000C;
constexpr uint16_t CMD_SET_X_ROT   = 0x000D;
constexpr uint16_t CMD_SET_Y_ROT   = 0x000E;
constexpr uint16_t CMD_SET_Z_ROT   = 0x000F;
constexpr uint16_t CMD_SET_ROT     = 0x0010;
constexpr uint16_t CMD_SET_X_SCALE = 0x0011;
constexpr uint16_t CMD_SET_Y_SCALE = 0x0012;
constexpr uint16_t CMD_SET_Z_SCALE = 0x0013;
constexpr uint16_t CMD_SET_SCALE   = 0x0014;

// Track indices
constexpr int TRACK_X_POS   = 0x00;
constexpr int TRACK_Y_POS   = 0x01;
constexpr int TRACK_Z_POS   = 0x02;
constexpr int TRACK_X_ROT   = 0x03;
constexpr int TRACK_Y_ROT   = 0x04;
constexpr int TRACK_Z_ROT   = 0x05;
constexpr int TRACK_X_SCALE = 0x06;
constexpr int TRACK_Y_SCALE = 0x07;
constexpr int TRACK_Z_SCALE = 0x08;

void JStudio::Engine::TDirectorActor::TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream)
{
	EUpdateType uType = (EUpdateType)updateType;

	switch (cmdType)
	{
	// Position
	case CMD_SET_X_POS:
		mTracks[TRACK_X_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_Y_POS:
		mTracks[TRACK_Y_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_Z_POS:
		mTracks[TRACK_Z_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_POS:
		mTracks[TRACK_X_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		mTracks[TRACK_Y_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		mTracks[TRACK_Z_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	// Rotation
	case CMD_SET_X_ROT:
		mTracks[TRACK_X_ROT].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_Y_ROT:
		mTracks[TRACK_Y_ROT].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_Z_ROT:
		mTracks[TRACK_Z_ROT].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_ROT:
		mTracks[TRACK_X_ROT].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		mTracks[TRACK_Y_ROT].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		mTracks[TRACK_Z_ROT].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	// Scale
	case CMD_SET_X_SCALE:
		mTracks[TRACK_X_SCALE].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_Y_SCALE:
		mTracks[TRACK_Y_SCALE].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_Z_SCALE:
		mTracks[TRACK_Z_SCALE].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_SCALE:
		mTracks[TRACK_X_SCALE].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		mTracks[TRACK_Y_SCALE].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		mTracks[TRACK_Z_SCALE].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	default:
		std::cout << "TObjectActor::TranslateCommand(): Command " << cmdType << std::endl;
		break;
	}
}
