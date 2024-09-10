#pragma once

#include "types.h"

#include <vector>

namespace JStudio
{
	namespace Engine
	{
		class TFunctionValue;

		class TFunctionValueAttribute_Refer
		{
			std::vector<TFunctionValue*> mContainer;

		public:
			TFunctionValueAttribute_Refer() { }
			virtual ~TFunctionValueAttribute_Refer() { }

			std::vector<TFunctionValue*>& GetContainer() { return mContainer; }
		};
	} // namespace Engine
} // namespace JStudio
