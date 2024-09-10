#include "engine/value/functionvaluetransition.hpp"

JStudio::Engine::TFunctionValueAttributeSet JStudio::Engine::TFunctionValueTransition::GetAttributeSet()
{
	return TFunctionValueAttributeSet() = { nullptr, nullptr, nullptr };
}

float JStudio::Engine::TFunctionValueTransition::Evaluate(int32_t frame)
{
	return 0.0f;
} // TFunctionValueTransition::Evaluate

bool JStudio::Engine::TFunctionValueTransition::Deserialize(bStream::CStream* stream)
{
	return true;
} // TFunctionValueTransition::Deserialize

bool JStudio::Engine::TFunctionValueTransition::Serialize(bStream::CStream* stream)
{
	return true;
} // TFunctionValueTransition::Serialize
