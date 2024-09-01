#include "engine/director/director_sound.hpp"

#include <bstream.h>

// Command IDs
constexpr uint16_t CMD_SET_X_POS = 0x0015;
constexpr uint16_t CMD_SET_Y_POS = 0x0016;
constexpr uint16_t CMD_SET_Z_POS = 0x0017;
constexpr uint16_t CMD_SET_POS = 0x0018;
constexpr uint16_t CMD_002E = 0x002E;
constexpr uint16_t CMD_002F = 0x002F;
constexpr uint16_t CMD_0038 = 0x0038;
constexpr uint16_t CMD_003C = 0x003C;
constexpr uint16_t CMD_003D = 0x003D;
constexpr uint16_t CMD_003E = 0x003E;
constexpr uint16_t CMD_003F = 0x003F;
constexpr uint16_t CMD_0040 = 0x0040;
constexpr uint16_t CMD_0041 = 0x0041;

// Track indices
constexpr int TRACK_X_POS = 0x00;
constexpr int TRACK_Y_POS = 0x01;
constexpr int TRACK_Z_POS = 0x02;

void JStudio::Engine::TDirectorSound::TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream)
{
	EUpdateType uType = (EUpdateType)updateType;

	switch (cmdType)
	{
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
	case CMD_002E:
		std::cout << "TObjectSound::TranslateCommand(): Command 0x002E" << std::endl;
		break;
	case CMD_002F:
		std::cout << "TObjectSound::TranslateCommand(): Command 0x002F" << std::endl;
		break;
	case CMD_0038:
		std::cout << "TObjectSound::TranslateCommand(): Command 0x0038" << std::endl;
		break;
	case CMD_003C:
		std::cout << "TObjectSound::TranslateCommand(): Command 0x003C" << std::endl;
		break;
	case CMD_003D:
		std::cout << "TObjectSound::TranslateCommand(): Command 0x003D" << std::endl;
		break;
	case CMD_003E:
		std::cout << "TObjectSound::TranslateCommand(): Command 0x003E" << std::endl;
		break;
	case CMD_003F:
		std::cout << "TObjectSound::TranslateCommand(): Command 0x003F" << std::endl;
		break;
	case CMD_0040:
		std::cout << "TObjectSound::TranslateCommand(): Command 0x0040" << std::endl;
		break;
	case CMD_0041:
		std::cout << "TObjectSound::TranslateCommand(): Command 0x0041" << std::endl;
		break;
	}
}
