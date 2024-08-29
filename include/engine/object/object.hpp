#pragma once

#include "types.h"

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class TObject
		{
		protected:
			std::string mName;

			virtual void TranslateCommand(uint32_t curFrame, uint16_t cmdType, uint16_t updateType, bStream::CStream* stream) = 0;

		public:
			TObject() { }
			virtual ~TObject() { }

			virtual bool Deserialize(bStream::CStream* stream);
			virtual bool Serialize(bStream::CStream* stream);
		};
	} // namespace Engine
} // namespace TObject
