#include "engine/value/functionvaluehermite.hpp"

#include <bstream.h>

JStudio::Engine::TFunctionValueAttributeSet JStudio::Engine::TFunctionValueHermite::GetAttributeSet()
{
	return TFunctionValueAttributeSet() = { nullptr, nullptr, nullptr };
} // TFunctionValueHermite::GetAttributeSet

float JStudio::Engine::TFunctionValueHermite::Evaluate(int32_t frame)
{
	return 0.0f;
} // TFunctionValueHermite::Evaluate

void JStudio::Engine::TFunctionValueHermite::LoadData(bStream::CStream* stream)
{

} // TFunctionValueHermite::LoadData
