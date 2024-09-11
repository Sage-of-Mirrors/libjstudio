#include "engine/value/variablevalue.hpp"
#include "engine/value/functionvalue.hpp"
#include "engine/enginedata.hpp"

float JStudio::Engine::TVariableValue::GetValue() const
{
	return mValue;
} // TVariableValue::GetValue

void JStudio::Engine::TVariableValue::Update(float deltaTime)
{
	switch (mUpdateType)
	{
	case EVariableUpdateType::LINEAR:
	{
		mValue = (float)mFrameCount * mUpdateRate * deltaTime;
		break;
	}
	case EVariableUpdateType::FUNCTION_VALUE:
	{
		TFunctionValue* funcVal = gEngineData.GetFunctionValue(mFunctionValueIndex);
		if (funcVal != nullptr)
		{
			mValue = funcVal->Evaluate((int32_t)mFrameCount);
		}
		break;
	}
	case EVariableUpdateType::NONE:
	default:
	{
		// Do nothing
		break;
	}
	}

	mFrameCount++;
} // TVariableValue::Update

void JStudio::Engine::TVariableValue::Reset()
{
	mFrameCount = 0;
} // TVariableValue::Reset

void JStudio::Engine::TVariableValue::SetImmediateUpdate(float value)
{
	mUpdateType = EVariableUpdateType::NONE;
	mValue = value;

	Reset();
} // TVariableValue::SetImmediateUpdate

void JStudio::Engine::TVariableValue::SetLinearUpdate(float updateRate)
{
	mUpdateType = EVariableUpdateType::LINEAR;
	mUpdateRate = updateRate;

	Reset();
} // TVariableValue::SetLinearUpdate

void JStudio::Engine::TVariableValue::SetFunctionValueUpdate(uint32_t funcValIdx)
{
	mUpdateType = EVariableUpdateType::FUNCTION_VALUE;
	mFunctionValueIndex = funcValIdx;

	Reset();
} // TVariableValue::SetFunctionValueUpdate
