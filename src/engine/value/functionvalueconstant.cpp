#include "engine/value/functionvalueconstant.hpp"

#include <bstream.h>

JStudio::Engine::TFunctionValueAttributeSet JStudio::Engine::TFunctionValueConstant::GetAttributeSet()
{
	return TFunctionValueAttributeSet() = { nullptr, nullptr, nullptr };
} // TFunctionValueConstant::GetAttributeSet

float JStudio::Engine::TFunctionValueConstant::Evaluate(int32_t frame)
{
	return mValue;
} // TFunctionValueConstant::Evaluate

void JStudio::Engine::TFunctionValueConstant::LoadData(bStream::CStream* stream)
{
	mValue = stream->readFloat();
} // TFunctionValueConstant::LoadData
