#include "engine/object/variablevalue.hpp"

float JStudio::Engine::TVariableValue::GetValue() const
{
	return mValue;
}

void JStudio::Engine::TVariableValue::SetValue(float value)
{
	mValue = value;
}

bool JStudio::Engine::TVariableValue::GetUpdateByFrameCount() const
{
	return bUpdateValueByFrameCount;
}

void JStudio::Engine::TVariableValue::SetUpdateByFrameCount(bool update)
{
	bUpdateValueByFrameCount = update;
	ResetFrameCount();
}

uint32_t JStudio::Engine::TVariableValue::GetFrameCount() const
{
	return mFrameCount;
}

void JStudio::Engine::TVariableValue::IncrementFrameCount()
{
	mFrameCount++;
}

void JStudio::Engine::TVariableValue::ResetFrameCount()
{
	mFrameCount = 0;
}

float JStudio::Engine::TVariableValue::GetUpdateRate() const
{
	return mUpdateRate;
}

void JStudio::Engine::TVariableValue::SetUpdateRate(float value)
{
	mUpdateRate = value;
}
