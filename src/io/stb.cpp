#include "io/stb.hpp"
#include "io/constants.hpp"

#include "engine/director/director.hpp"
#include "engine/directors.hpp"

#include "engine/value/functionvalue.hpp"
#include "engine/functionvalues.hpp"

#include <bStream.h>
#include <iostream>

constexpr uint16_t FUNCVAL_CMD_PREPARE = 0x0000;
constexpr uint16_t FUNCVAL_CMD_SET_KEY_DATA = 0x0001;
constexpr uint16_t FUNCVAL_CMD_SET_REFERRALS = 0x0010;
constexpr uint16_t FUNCVAL_CMD_SET_REFERRALS_BY_INDEX = 0x0011;
constexpr uint16_t FUNCVAL_CMD_SET_RANGE_BOUNDS = 0x0012;
constexpr uint16_t FUNCVAL_CMD_SET_RANGE_PROGRESS_TYPE = 0x0013;
constexpr uint16_t FUNCVAL_CMD_SET_RANGE_ADJUST_TYPE = 0x0014;
constexpr uint16_t FUNCVAL_CMD_SET_RANGE_EXTRAPOLATION_TYPES = 0x0015;
constexpr uint16_t FUNCVAL_CMD_SET_INTERPOLATION_TYPE = 0x0016;

void JStudio::IO::STBFile::LoadFunctionValues(bStream::CStream* stream)
{
	assert(stream->readUInt32() == FVB_MAGIC);
	assert(stream->readUInt16() == STB_BOM);

	uint16_t m000E = stream->readUInt16(); // Unsure. Always 0x0100?
	uint32_t fvbSize = stream->readUInt32();
	uint32_t fvbCount = stream->readUInt32();

	for (uint32_t i = 0; i < fvbCount; i++)
	{
		uint32_t funcValSize = stream->readUInt32();
		size_t nextFuncValOffset = stream->tell() + (size_t)(funcValSize - sizeof(uint32_t)); // Subtract the length of the size from the next offset.

		uint16_t funcValType = stream->readUInt16(); // What type of funcvalue this object is.
		uint16_t m0006 = stream->readUInt16(); // Unsure.

		Engine::TFunctionValue* funcValObj = nullptr;

		switch (funcValType)
		{
		case FUNCVAL_COMPOSITE:
			funcValObj = new Engine::TFunctionValueComposite();
			break;
		case FUNCVAL_CONSTANT:
			funcValObj = new Engine::TFunctionValueConstant();
			break;
		case FUNCVAL_TRANSITION:
			funcValObj = new Engine::TFunctionValueTransition();
			break;
		case FUNCVAL_LIST:
			funcValObj = new Engine::TFunctionValueList();
			break;
		case FUNCVAL_LIST_PARAMETER:
			funcValObj = new Engine::TFunctionValueListParameter();
			break;
		case FUNCVAL_HERMITE:
			funcValObj = new Engine::TFunctionValueHermite();
			break;
		}

		if (funcValObj != nullptr)
		{
			ConfigureFunctionValue(stream, funcValObj);
			mFunctionValues.push_back(funcValObj);
		}

		stream->seek(nextFuncValOffset);
	}
} // STBFile::LoadFunctionValues

void JStudio::IO::STBFile::ConfigureFunctionValue(bStream::CStream* stream, Engine::TFunctionValue* funcValue)
{
	Engine::TFunctionValueAttributeSet attributes = funcValue->GetAttributeSet();

	uint16_t commandSize = stream->readUInt16();
	while (commandSize != 0)
	{
		uint16_t commandType = stream->readUInt16();
		size_t nextCmdOffset = stream->tell() + (size_t)commandSize;

		switch (commandType)
		{
		case FUNCVAL_CMD_PREPARE:
		{
			break;
		}
		case FUNCVAL_CMD_SET_KEY_DATA:
		{
			break;
		}
		case FUNCVAL_CMD_SET_REFERRALS:
		{
			if (attributes.Refer != nullptr)
			{
				// TODO: Set referrals by name
			}

			break;
		}
		case FUNCVAL_CMD_SET_REFERRALS_BY_INDEX:
		{
			if (attributes.Refer != nullptr)
			{
				// TODO: Set referrals by index
			}

			break;
		}
		case FUNCVAL_CMD_SET_RANGE_BOUNDS:
		{
			float rangeStart = stream->readFloat();
			float rangeEnd = stream->readFloat();

			if (attributes.Range != nullptr)
			{
				attributes.Range->SetRange(rangeStart, rangeEnd);
			}

			break;
		}
		case FUNCVAL_CMD_SET_RANGE_PROGRESS_TYPE:
		{
			Engine::EProgressType progressType = (Engine::EProgressType)stream->readUInt32();

			if (attributes.Range != nullptr)
			{
				attributes.Range->SetProgressType(progressType);
			}

			break;
		}
		case FUNCVAL_CMD_SET_RANGE_ADJUST_TYPE:
		{
			Engine::EAdjustType adjustType = (Engine::EAdjustType)stream->readUInt32();

			if (attributes.Range != nullptr)
			{
				attributes.Range->SetAdjustType(adjustType);
			}

			break;
		}
		case FUNCVAL_CMD_SET_RANGE_EXTRAPOLATION_TYPES:
		{
			Engine::EExtrapolateType underflowExtrapolate = (Engine::EExtrapolateType)stream->readUInt16();
			Engine::EExtrapolateType overflowExtrapolate = (Engine::EExtrapolateType)stream->readUInt16();

			if (attributes.Range != nullptr)
			{
				attributes.Range->SetExtrapolationTypes(underflowExtrapolate, overflowExtrapolate);
			}

			break;
		}
		case FUNCVAL_CMD_SET_INTERPOLATION_TYPE:
		{
			Engine::EInterpolateType interpolateType = (Engine::EInterpolateType)stream->readUInt32();

			if (attributes.Interpolate != nullptr)
			{
				attributes.Interpolate->SetInterpolateType(interpolateType);
			}

			break;
		}
		}

		stream->seek(nextCmdOffset);
		commandSize = stream->readUInt16();
	}
} // STBFile::ConfigureFunctionValue

void JStudio::IO::STBFile::LoadObject(uint32_t objectFourcc, bStream::CStream* stream)
{
	Engine::TDirector* newDirector = nullptr;

	switch (objectFourcc)
	{
	case FOURCC_ACTOR:
		newDirector = new Engine::TDirectorActor();
		break;
	case FOURCC_CAMERA:
		newDirector = new Engine::TDirectorCamera();
		break;
	case FOURCC_CONTROL:
		newDirector = new Engine::TDirectorControl();
		break;
	case FOURCC_MESSAGE:
		newDirector = new Engine::TDirectorMessage();
		break;
	case FOURCC_PARTICLE:
		newDirector = new Engine::TDirectorParticle();
		break;
	case FOURCC_SOUND:
		newDirector = new Engine::TDirectorSound();
		break;
	default:
		std::cout << "STBFile::Deserialize(): Unknown object FourCC " << objectFourcc << "." << std::endl;
		break;
	}

	if (newDirector != nullptr && newDirector->Deserialize(stream, mLength))
	{
		mDirectors.push_back(newDirector);
	}
} // STBFile::LoadObject

bool JStudio::IO::STBFile::Deserialize(bStream::CStream* stream)
{
	if (stream == nullptr)
	{
		std::cout << "STBFile::Deserialize(): Input stream was nullptr." << std::endl;
		return false;
	}

	if (stream->readUInt32() != STB_MAGIC)
	{
		std::cout << "STBFile::Deserialize(): Input stream is not an STB file." << std::endl;
		return false;
	}
	if (stream->readUInt16() != STB_BOM)
	{
		std::cout << "STBFile::Deserialize(): STB file not big endian?" << std::endl;
		return false;
	}
	if (stream->readUInt16() != STB_VERSION)
	{
		std::cout << "STBFile::Deserialize(): STB file not a recognized version." << std::endl;
		return false;
	}

	uint32_t fileSize = stream->readUInt32();
	uint32_t objectCount = stream->readUInt32();

	char watermark[8] { };
	stream->readBytesTo((uint8_t*)watermark, 8);
	if (std::strcmp(watermark, STB_WATERMARK) != 0)
	{
		std::cout << "STBFile::Deserialize(): Unexpected watermark? (got \'" << watermark << "\')" << std::endl;
	}

	// These two fields are the same in most files I've seen...
	assert(stream->readUInt32() == 0);
	assert(stream->readUInt32() == 3);

	// Read in the objects.
	for (uint32_t i = 0; i < objectCount; i++)
	{
		uint32_t objectSize = stream->readUInt32();
		uint32_t objectFourcc = stream->readUInt32();

		size_t nextObjectOffset = stream->tell() + (size_t)(objectSize - sizeof(uint32_t) * 2); // Subtract 8 from the size because it includes the FourCC + the size itself.

		if (objectFourcc == FOURCC_FUNCVALUES)
		{
			LoadFunctionValues(stream);
		}
		else
		{
			LoadObject(objectFourcc, stream);
		}

		stream->seek(nextObjectOffset);
	}

	return true;
} // STBFile::Deserialize

bool JStudio::IO::STBFile::Serialize(bStream::CStream* stream)
{
	return true;
} // STBFile::Serialize
