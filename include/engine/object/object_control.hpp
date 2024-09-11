#pragma once

#include "types.h"
#include "object.hpp"

namespace JStudio
{
	namespace Engine
	{
		class TObjectControl : public TObject
		{
		public:
			TObjectControl()
			{
				mType = EObjectType::CONTROL;
			}

			virtual ~TObjectControl() { }
		};
	} // namespace Engine
} // namespace JStudio
