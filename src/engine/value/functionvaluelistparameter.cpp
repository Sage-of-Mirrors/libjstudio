#include "engine/value/functionvaluelistparameter.hpp"

float JStudio::Engine::TFunctionValueListParameter::Evaluate(int32_t frame)
{
	return 0.0f;
} // TFunctionValueListParameter::Evaluate

bool JStudio::Engine::TFunctionValueListParameter::Deserialize(bStream::CStream* stream)
{
	return true;
} // TFunctionValueListParameter::Deserialize

bool JStudio::Engine::TFunctionValueListParameter::Serialize(bStream::CStream* stream)
{
	return true;
} // TFunctionValueListParameter::Serialize
