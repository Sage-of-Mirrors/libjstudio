#include "engine/value/functionvaluelist.hpp"

JStudio::Engine::TFunctionValueAttributeSet JStudio::Engine::TFunctionValueList::GetAttributeSet()
{
	return TFunctionValueAttributeSet() = { nullptr, nullptr, nullptr };
}

float JStudio::Engine::TFunctionValueList::Evaluate(int32_t frame)
{
	return 0.0f;
} // TFunctionValueList::Evaluate

bool JStudio::Engine::TFunctionValueList::Deserialize(bStream::CStream* stream)
{
	return true;
} // TFunctionValueList::Deserialize

bool JStudio::Engine::TFunctionValueList::Serialize(bStream::CStream* stream)
{
	return true;
} // TFunctionValueList::Serialize
