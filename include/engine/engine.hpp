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
		class TObjectCamera;

		class TEngine
		{
			std::vector<TDirector*> mDirectors;
			std::vector<TObject*> mObjects;

			TObjectCamera* mCameraObject;

			uint32_t mLength;

		public:
			TEngine() : mCameraObject(nullptr), mLength(0) { }
			virtual ~TEngine();

			bool LoadBinary(std::filesystem::path filePath);
			bool LoadBinary(bStream::CStream* stream);

			uint32_t GetLength() const { return mLength; }
			TObjectCamera* GetCameraObject() { return mCameraObject; }

			void Update(const uint32_t& frame, float deltaTime);

			bool IsPuasedForMessage();
			void DismissMessage();
		};
	} // namespace Engine
} // namespace JStudio

