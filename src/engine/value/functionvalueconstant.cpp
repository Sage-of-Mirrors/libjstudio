#include "engine/value/functionvalueconstant.hpp"

float JStudio::Engine::TFunctionValueConstant::Evaluate(int32_t frame)
{
	return 0.0f;
} // TFunctionValueConstant::Evaluate

bool JStudio::Engine::TFunctionValueConstant::Deserialize(bStream::CStream* stream)
{
	return true;
} // TFunctionValueConstant::Deserialize

bool JStudio::Engine::TFunctionValueConstant::Serialize(bStream::CStream* stream)
{
	return true;
} // TFunctionValueConstant::Serialize