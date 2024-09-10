#include "engine/value/functionvaluehermite.hpp"

JStudio::Engine::TFunctionValueAttributeSet JStudio::Engine::TFunctionValueHermite::GetAttributeSet()
{
	return TFunctionValueAttributeSet() = { nullptr, nullptr, nullptr };
}

float JStudio::Engine::TFunctionValueHermite::Evaluate(int32_t frame)
{
	return 0.0f;
} // TFunctionValueHermite::Evaluate

bool JStudio::Engine::TFunctionValueHermite::Deserialize(bStream::CStream* stream)
{
	return true;
} // TFunctionValueHermite::Deserialize

bool JStudio::Engine::TFunctionValueHermite::Serialize(bStream::CStream* stream)
{
	return true;
} // TFunctionValueHermite::Serialize
