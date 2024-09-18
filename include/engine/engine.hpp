#pragma once

#include "types.h"
#include "engine/track/meta.hpp"

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
		class TObjectControl;

		class TEngine
		{
			std::vector<TDirector*> mDirectors;
			std::vector<TObject*> mObjects;

			TObjectCamera* mCameraObject;
			TObjectControl* mControlObject;

			uint32_t mLength;

		public:
			TEngine() : mCameraObject(nullptr), mControlObject(nullptr), mLength(0) { }
			virtual ~TEngine();

			bool LoadBinary(std::filesystem::path filePath);
			bool LoadBinary(bStream::CStream* stream);

			uint32_t GetLength() const { return mLength; }
			TObjectCamera* GetCameraObject() { return mCameraObject; }
			std::vector<TDirectorMetadata> GetDirectorMetadata();

			void Update(const uint32_t& frame, float deltaTime);

			bool IsPuasedForMessage();
			void DismissMessage();
		};
	} // namespace Engine
} // namespace JStudio

