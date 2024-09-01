#pragma once

#include "types.h"

#include <filesystem>
#include <vector>

namespace bStream
{
	class CStream;
} // namespace bStream

namespace JStudio
{
	namespace Engine
	{
		class TDirector;
		class TObject;

		class TEngine
		{
			std::vector<TDirector*> mDirectors;
			std::vector<TObject*> mObjects;

			uint32_t mLength;

		public:
			TEngine() { }
			virtual ~TEngine();

			bool LoadBinary(std::filesystem::path filePath);
			bool LoadBinary(bStream::CStream* stream);

			uint32_t GetLength() const { return mLength; }

			void Update(const uint32_t& frame, float deltaTime);
		};
	} // namespace Engine
} // namespace JStudio

