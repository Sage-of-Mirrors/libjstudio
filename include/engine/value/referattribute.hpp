#pragma once

#include "types.h"

#include <vector>

namespace JStudio
{
	namespace Engine
	{
		class TFunctionValue;

		class IReferAttribute
		{
			std::vector<TFunctionValue*> mContainer;

		public:
			IReferAttribute() { }
			virtual ~IReferAttribute() { }

			std::vector<TFunctionValue*>& GetContainer() { return mContainer; }
		};
	} // namespace Engine
} // namespace JStudio
