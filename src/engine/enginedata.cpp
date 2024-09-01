#include "engine/enginedata.hpp"
#include "engine/object/functionvalue.hpp"

JStudio::Engine::TEngineData gEngineData { };

JStudio::Engine::TEngineData::~TEngineData()
{
	for (TFunctionValue* funcvalue : mFunctionValues)
	{
		delete funcvalue;
	}
	mFunctionValues.clear();
}
