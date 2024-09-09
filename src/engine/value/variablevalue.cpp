#include "engine/value/variablevalue.hpp"

float JStudio::Engine::TVariableValue::GetValue() const
{
	return mValue;
} // TVariableValue::GetValue

void JStudio::Engine::TVariableValue::SetValue(float value)
{
	mValue = value;
} // TVariableValue::SetValue

bool JStudio::Engine::TVariableValue::GetUpdateByFrameCount() const
{
	return bUpdateValueByFrameCount;
} // TVariableValue::GetUpdateByFrameCount

void JStudio::Engine::TVariableValue::SetUpdateByFrameCount(bool update)
{
	bUpdateValueByFrameCount = update;
	ResetFrameCount();
} // TVariableValue::SetUpdateByFrameCount

uint32_t JStudio::Engine::TVariableValue::GetFrameCount() const
{
	return mFrameCount;
} // TVariableValue::GetFrameCount

void JStudio::Engine::TVariableValue::IncrementFrameCount()
{
	mFrameCount++;
} // TVariableValue::IncrementFrameCount

void JStudio::Engine::TVariableValue::ResetFrameCount()
{
	mFrameCount = 0;
} // TVariableValue::ResetFrameCount

float JStudio::Engine::TVariableValue::GetUpdateRate() const
{
	return mUpdateRate;
} // TVariableValue::GetUpdateRate

void JStudio::Engine::TVariableValue::SetUpdateRate(float value)
{
	mUpdateRate = value;
} // TVariableValue::SetUpdateRate
