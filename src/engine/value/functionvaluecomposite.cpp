#include "engine/value/functionvaluecomposite.hpp"

JStudio::Engine::TFunctionValueAttributeSet JStudio::Engine::TFunctionValueComposite::GetAttributeSet()
{
	return TFunctionValueAttributeSet() = { nullptr, nullptr, nullptr };
}

float JStudio::Engine::TFunctionValueComposite::Evaluate(int32_t frame)
{
	return 0.0f;
} // TFunctionValueComposite::Evaluate

bool JStudio::Engine::TFunctionValueComposite::Deserialize(bStream::CStream* stream)
{
	return true;
} // TFunctionValueComposite::Deserialize

bool JStudio::Engine::TFunctionValueComposite::Serialize(bStream::CStream* stream)
{
	return true;
} // TFunctionValueComposite::Serialize
