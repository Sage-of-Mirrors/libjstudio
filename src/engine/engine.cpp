#include "engine/engine.hpp"
#include "engine/director/director.hpp"
#include "engine/object/object.hpp"
#include "engine/enginedata.hpp"

#include "io/stb.hpp"

#include <bStream.h>

JStudio::Engine::TEngine::~TEngine()
{
	for (TDirector* director : mDirectors)
	{
		delete director;
	}
	mDirectors.clear();

	for (TObject* object : mObjects)
	{
		delete object;
	}
	mObjects.clear();
} // TEngine::~TEngine

bool JStudio::Engine::TEngine::LoadBinary(std::filesystem::path path)
{
	if (!std::filesystem::exists(path))
	{
		return false;
	}

	bStream::CFileStream stream(path.generic_u8string(), bStream::Big, bStream::In);
	return LoadBinary(&stream);
} // TEngine::LoadBinary

bool JStudio::Engine::TEngine::LoadBinary(bStream::CStream* stream)
{
	IO::STBFile file;
	if (!file.Deserialize(stream))
	{
		return false;
	}

	mLength = file.GetLength();
	assert(mLength != 0);

	mDirectors = file.GetDirectors();
	assert(mDirectors.size() != 0);

	std::vector<TFunctionValue*> funcValues = file.GetFunctionValues();
	assert(funcValues.size() != 0);

	gEngineData.SetFunctionValues(file.GetFunctionValues());

	for (TDirector* director : mDirectors)
	{
		assert(director != nullptr);
		TObject* object = director->CreateObject();

		assert(object != nullptr);
		mObjects.push_back(object);

		if (object->GetObjectType() == EObjectType::CAMERA)
		{
			mCameraObject = (TObjectCamera*)object;
		}
	}

	return true;
} // TEngine::LoadBinary

void JStudio::Engine::TEngine::Update(const uint32_t& frame, float deltaTime)
{
	for (uint32_t i = 0; i < (uint32_t)mDirectors.size(); i++)
	{
		mObjects[i]->UpdateVariables(mDirectors[i], frame, deltaTime);
		mObjects[i]->Update();
	}
} // TEngine::Update

bool JStudio::Engine::TEngine::IsPuasedForMessage()
{
	return gEngineData.GetHaltForInput();
} // TEngine::IsPuasedForMessage

void JStudio::Engine::TEngine::DismissMessage()
{
	gEngineData.SetHaltForInput(false);
} // TEngine::DismissMessage
