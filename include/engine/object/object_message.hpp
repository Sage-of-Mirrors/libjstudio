#pragma once

#include "types.h"
#include "object.hpp"

namespace JStudio
{
	namespace Engine
	{
		class TObjectMessage : public TObject
		{
		public:
			TObjectMessage()
			{
				mType = EObjectType::MESSAGE;
			}

			virtual ~TObjectMessage() { }
		};
	} // namespace Engine
} // namespace JStudio
