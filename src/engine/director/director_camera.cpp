#include "engine/director/director_camera.hpp"

#include <bstream.h>

// Command IDs
constexpr uint16_t CMD_SET_EYE_X_POS     = 0x0015;
constexpr uint16_t CMD_SET_EYE_Y_POS     = 0x0016;
constexpr uint16_t CMD_SET_EYE_Z_POS     = 0x0017;
constexpr uint16_t CMD_SET_EYE_POS       = 0x0018;
constexpr uint16_t CMD_SET_TARGET_X_POS  = 0x0019;
constexpr uint16_t CMD_SET_TARGET_Y_POS  = 0x001A;
constexpr uint16_t CMD_SET_TARGET_Z_POS  = 0x001B;
constexpr uint16_t CMD_SET_TARGET_POS    = 0x001C;
// 0x001D to 0x0025 are unused
constexpr uint16_t CMD_SET_UNK_0026      = 0x0026;
constexpr uint16_t CMD_SET_UNK_0027      = 0x0027;
constexpr uint16_t CMD_SET_DIST_NEAR     = 0x0028;
constexpr uint16_t CMD_SET_DIST_FAR      = 0x0029;
constexpr uint16_t CMD_SET_DIST_NEAR_FAR = 0x002A;

// Track indices
constexpr int TRACK_EYE_X_POS    = 0x00;
constexpr int TRACK_EYE_Y_POS    = 0x01;
constexpr int TRACK_EYE_Z_POS    = 0x02;
constexpr int TRACK_TARGET_X_POS = 0x03;
constexpr int TRACK_TARGET_Y_POS = 0x04;
constexpr int TRACK_TARGET_Z_POS = 0x05;
constexpr int TRACK_UNK_0026     = 0x06;
constexpr int TRACK_UNK_0027     = 0x07;
constexpr int TRACK_DIST_NEAR    = 0x08;
constexpr int TRACK_DIST_FAR     = 0x09;

void JStudio::Engine::TDirectorCamera::TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream)
{
	EUpdateType uType = (EUpdateType)updateType;

	switch (cmdType)
	{
	// Eye position (where the camera is)
	case CMD_SET_EYE_X_POS:
		mTracks[TRACK_EYE_X_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_EYE_Y_POS:
		mTracks[TRACK_EYE_Y_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_EYE_Z_POS:
		mTracks[TRACK_EYE_Z_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_EYE_POS:
		mTracks[TRACK_EYE_X_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		mTracks[TRACK_EYE_Y_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		mTracks[TRACK_EYE_Z_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;

	// Target position (where the camera is looking)
	case CMD_SET_TARGET_X_POS:
		mTracks[TRACK_TARGET_X_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_TARGET_Y_POS:
		mTracks[TRACK_TARGET_Y_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_TARGET_Z_POS:
		mTracks[TRACK_TARGET_Z_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_TARGET_POS:
		mTracks[TRACK_TARGET_X_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		mTracks[TRACK_TARGET_Y_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		mTracks[TRACK_TARGET_Z_POS].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;

	// ?
	case CMD_SET_UNK_0026:
		mTracks[TRACK_UNK_0026].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_UNK_0027:
		mTracks[TRACK_UNK_0027].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;

	// Near/far distance
	case CMD_SET_DIST_NEAR:
		mTracks[TRACK_DIST_NEAR].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_DIST_FAR:
		mTracks[TRACK_DIST_FAR].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	case CMD_SET_DIST_NEAR_FAR:
		mTracks[TRACK_DIST_NEAR].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		mTracks[TRACK_DIST_FAR].AddKey(uType == EUpdateType::FUNCVALUE_INDEX ? (float)stream->readUInt32() : stream->readFloat(), curFrame, uType);
		break;
	default:
		std::cout << "TObjectCamera::TranslateCommand(): Command " << cmdType << " with update type " << updateType << std::endl;
		break;
	}
}
