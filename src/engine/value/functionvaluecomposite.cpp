#include "engine/value/functionvaluecomposite.hpp"

#include <bstream.h>

JStudio::Engine::TFunctionValueAttributeSet JStudio::Engine::TFunctionValueComposite::GetAttributeSet()
{
	return TFunctionValueAttributeSet() = { nullptr, nullptr, nullptr };
} // TFunctionValueComposite::GetAttributeSet

float JStudio::Engine::TFunctionValueComposite::Evaluate(int32_t frame)
{
	return 0.0f;
} // TFunctionValueComposite::Evaluate

void JStudio::Engine::TFunctionValueComposite::LoadData(bStream::CStream* stream)
{

} // TFunctionValueComposite::LoadData
