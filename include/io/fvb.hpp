#pragma once

#include "types.h"

#include <vector>

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class TFunctionValue;
	} // namespace Engine

	namespace IO
	{
		class FunctionValueIO
		{
			static void ConfigureFunctionValue(bStream::CStream* stream, Engine::TFunctionValue* funcValue);

		public:
			FunctionValueIO() { }
			virtual ~FunctionValueIO() { }

			static std::vector<Engine::TFunctionValue*> LoadFunctionValues(bStream::CStream* stream);
			static void SaveFunctionValues(std::vector<Engine::TFunctionValue*>& functionValues);
		};
	} // namespace IO
} // namespace JStudio
