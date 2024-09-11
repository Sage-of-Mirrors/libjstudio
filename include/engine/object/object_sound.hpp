#pragma once

#include "types.h"
#include "object.hpp"

namespace JStudio
{
	namespace Engine
	{
		class TObjectSound : public TObject
		{
		public:
			TObjectSound()
			{
				mType = EObjectType::SOUND;
			}

			virtual ~TObjectSound() { }
		};
	} // namespace Engine
} // namespace JStudio
