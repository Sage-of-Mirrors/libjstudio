#include "engine/value/functionvaluelist.hpp"

#include <bstream.h>

JStudio::Engine::TFunctionValueAttributeSet JStudio::Engine::TFunctionValueList::GetAttributeSet()
{
	return TFunctionValueAttributeSet() = { nullptr, nullptr, nullptr };
} // TFunctionValueList::GetAttributeSet

float JStudio::Engine::TFunctionValueList::Evaluate(int32_t frame)
{
	return 0.0f;
} // TFunctionValueList::Evaluate

void JStudio::Engine::TFunctionValueList::LoadData(bStream::CStream* stream)
{

} // TFunctionValueList::LoadData
