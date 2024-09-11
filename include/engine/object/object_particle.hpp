#pragma once

#include "types.h"
#include "object.hpp"

namespace JStudio
{
	namespace Engine
	{
		class TObjectParticle : public TObject
		{
		public:
			TObjectParticle()
			{
				mType = EObjectType::PARTICLE;
			}

			virtual ~TObjectParticle() { }
		};
	} // namespace Engine
} // namespace JStudio
