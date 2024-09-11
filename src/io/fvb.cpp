#include "io/fvb.hpp"
#include "io/constants.hpp"

#include "engine/value/functionvalue.hpp"
#include "engine/functionvalues.hpp"

#include <bStream.h>
#include <cmath>

constexpr uint16_t FUNCVAL_CMD_PREPARE = 0x0000;
constexpr uint16_t FUNCVAL_CMD_SET_KEY_DATA = 0x0001;
constexpr uint16_t FUNCVAL_CMD_SET_REFERRALS = 0x0010;
constexpr uint16_t FUNCVAL_CMD_SET_REFERRALS_BY_INDEX = 0x0011;
constexpr uint16_t FUNCVAL_CMD_SET_RANGE_BOUNDS = 0x0012;
constexpr uint16_t FUNCVAL_CMD_SET_RANGE_PROGRESS_TYPE = 0x0013;
constexpr uint16_t FUNCVAL_CMD_SET_RANGE_ADJUST_TYPE = 0x0014;
constexpr uint16_t FUNCVAL_CMD_SET_RANGE_EXTRAPOLATION_TYPES = 0x0015;
constexpr uint16_t FUNCVAL_CMD_SET_INTERPOLATION_TYPE = 0x0016;

constexpr float SECONDS_TO_FRAMES = 30.0f;
constexpr float FRAMES_TO_SECONDS = 1.0f / 30.0f;

std::vector<JStudio::Engine::TFunctionValue*> JStudio::IO::FunctionValueIO::LoadFunctionValues(bStream::CStream* stream)
{
	assert(stream->readUInt32() == FVB_MAGIC);
	assert(stream->readUInt16() == STB_BOM);

	std::vector<Engine::TFunctionValue*> funcValues;

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
			funcValues.push_back(funcValObj);
		}

		stream->seek(nextFuncValOffset);
	}

	return funcValues;
} // FunctionValueIO::LoadFunctionValues

void JStudio::IO::FunctionValueIO::ConfigureFunctionValue(bStream::CStream* stream, Engine::TFunctionValue* funcValue)
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
			funcValue->LoadData(stream);
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
			float rangeStart = std::roundf(stream->readFloat() * SECONDS_TO_FRAMES);
			float rangeEnd = std::roundf(stream->readFloat() * SECONDS_TO_FRAMES);

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
} // FunctionValueIO::ConfigureFunctionValue

void JStudio::IO::FunctionValueIO::SaveFunctionValues(std::vector<Engine::TFunctionValue*>& functionValues)
{

} // FunctionValueIO::SaveFunctionValues
