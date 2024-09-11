#include "io/stb.hpp"
#include "io/fvb.hpp"
#include "io/constants.hpp"

#include "engine/director/director.hpp"
#include "engine/directors.hpp"

#include "engine/value/functionvaluelistparameter.hpp"

#include <bStream.h>
#include <iostream>

void JStudio::IO::STBFile::LoadObject(uint32_t objectFourcc, bStream::CStream* stream)
{
	Engine::TDirector* newDirector = nullptr;

	switch (objectFourcc)
	{
	case FOURCC_ACTOR:
		newDirector = new Engine::TDirectorActor();
		break;
	case FOURCC_CAMERA:
		newDirector = new Engine::TDirectorCamera();
		break;
	case FOURCC_CONTROL:
		newDirector = new Engine::TDirectorControl();
		break;
	case FOURCC_MESSAGE:
		newDirector = new Engine::TDirectorMessage();
		break;
	case FOURCC_PARTICLE:
		newDirector = new Engine::TDirectorParticle();
		break;
	case FOURCC_SOUND:
		newDirector = new Engine::TDirectorSound();
		break;
	default:
		std::cout << "STBFile::Deserialize(): Unknown object FourCC " << objectFourcc << "." << std::endl;
		break;
	}

	if (newDirector != nullptr && newDirector->Deserialize(stream, mLength))
	{
		mDirectors.push_back(newDirector);
	}
} // STBFile::LoadObject

bool JStudio::IO::STBFile::Deserialize(bStream::CStream* stream)
{
	if (stream == nullptr)
	{
		std::cout << "STBFile::Deserialize(): Input stream was nullptr." << std::endl;
		return false;
	}

	if (stream->readUInt32() != STB_MAGIC)
	{
		std::cout << "STBFile::Deserialize(): Input stream is not an STB file." << std::endl;
		return false;
	}
	if (stream->readUInt16() != STB_BOM)
	{
		std::cout << "STBFile::Deserialize(): STB file not big endian?" << std::endl;
		return false;
	}
	if (stream->readUInt16() != STB_VERSION)
	{
		std::cout << "STBFile::Deserialize(): STB file not a recognized version." << std::endl;
		return false;
	}

	uint32_t fileSize = stream->readUInt32();
	uint32_t objectCount = stream->readUInt32();

	char watermark[8] { };
	stream->readBytesTo((uint8_t*)watermark, 8);
	if (std::strcmp(watermark, STB_WATERMARK) != 0)
	{
		std::cout << "STBFile::Deserialize(): Unexpected watermark? (got \'" << watermark << "\')" << std::endl;
	}

	// These two fields are the same in most files I've seen...
	assert(stream->readUInt32() == 0);
	assert(stream->readUInt32() == 3);

	// Read in the objects.
	for (uint32_t i = 0; i < objectCount; i++)
	{
		uint32_t objectSize = stream->readUInt32();
		uint32_t objectFourcc = stream->readUInt32();

		size_t nextObjectOffset = stream->tell() + (size_t)(objectSize - sizeof(uint32_t) * 2); // Subtract 8 from the size because it includes the FourCC + the size itself.

		if (objectFourcc == FOURCC_FUNCVALUES)
		{
			mFunctionValues = FunctionValueIO::LoadFunctionValues(stream);
		}
		else
		{
			LoadObject(objectFourcc, stream);
		}

		stream->seek(nextObjectOffset);
	}

	return true;
} // STBFile::Deserialize

bool JStudio::IO::STBFile::Serialize(bStream::CStream* stream)
{
	return true;
} // STBFile::Serialize
