#include "engine/enginedata.hpp"
#include "engine/value/functionvalue.hpp"

JStudio::Engine::TEngineData::~TEngineData()
{
	for (TFunctionValue* funcvalue : mFunctionValues)
	{
		delete funcvalue;
	}
	mFunctionValues.clear();
} // TEngineData::~TEngineData

JStudio::Engine::TFunctionValue* JStudio::Engine::TEngineData::GetFunctionValue(uint32_t index)
{
	if (index >= mFunctionValues.size())
	{
		return nullptr;
	}

	return mFunctionValues[index];
} // TEngineData::GetFunctionValue
