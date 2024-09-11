#pragma once

#include "types.h"
#include "object.hpp"

namespace JStudio
{
	namespace Engine
	{
		class TObjectActor : public TObject
		{
		public:
			TObjectActor()
			{
				mType = EObjectType::ACTOR;
			}

			virtual ~TObjectActor() { }
		};
	} // namespace Engine
} // namespace JStudio
