#include "engine/engine.hpp"
#include "engine/director/director.hpp"
#include "engine/object/object.hpp"
#include "engine/enginedata.hpp"

#include "engine/object/object_camera.hpp"

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
}

bool JStudio::Engine::TEngine::LoadBinary(std::filesystem::path path)
{
	if (!std::filesystem::exists(path))
	{
		return false;
	}

	bStream::CFileStream stream(path.generic_u8string(), bStream::Big, bStream::In);
	return LoadBinary(&stream);
}

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
	//assert(funcValues.size() != 0);
	gEngineData.SetFunctionValues(file.GetFunctionValues());

	for (TDirector* director : mDirectors)
	{
		assert(director != nullptr);
		TObject* object = director->CreateObject();

		assert(object != nullptr);
		mObjects.push_back(object);
	}

	return true;
}

void JStudio::Engine::TEngine::Update(const uint32_t& frame, float deltaTime)
{
	for (uint32_t i = 0; i < (uint32_t)mDirectors.size(); i++)
	{
		mObjects[i]->UpdateVariables(mDirectors[i], frame, deltaTime);
		mObjects[i]->Update();
	}
}
