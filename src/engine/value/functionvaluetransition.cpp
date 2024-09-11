#include "engine/value/functionvaluetransition.hpp"

#include <bstream.h>

JStudio::Engine::TFunctionValueAttributeSet JStudio::Engine::TFunctionValueTransition::GetAttributeSet()
{
	return TFunctionValueAttributeSet() = { nullptr, nullptr, nullptr };
} // TFunctionValueTransition::GetAttributeSet

float JStudio::Engine::TFunctionValueTransition::Evaluate(int32_t frame)
{
	return 0.0f;
} // TFunctionValueTransition::Evaluate

void JStudio::Engine::TFunctionValueTransition::LoadData(bStream::CStream* stream)
{

} // TFunctionValueTransition::LoadData
