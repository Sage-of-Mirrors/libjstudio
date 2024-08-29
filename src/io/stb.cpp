#include "io/stb.hpp"
#include "io/constants.hpp"

#include "engine/object/object.hpp"
#include "engine/objects.hpp"

#include <bStream.h>
#include <iostream>

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

		size_t nextObjectOffset = stream->tell() + (size_t)(objectSize - 8); // Subtract 8 from the size because it includes the FourCC + the size itself.

		if (objectFourcc == FOURCC_FUNCVALUES)
		{
			continue;
		}

		Engine::TObject* newObject = nullptr;

		switch (objectFourcc)
		{
		case FOURCC_ACTOR:
			newObject = new Engine::TObjectActor();
			break;
		case FOURCC_CAMERA:
			newObject = new Engine::TObjectCamera();
			break;
		case FOURCC_CONTROL:
			newObject = new Engine::TObjectControl();
			break;
		case FOURCC_MESSAGE:
			newObject = new Engine::TObjectMessage();
			break;
		case FOURCC_PARTICLE:
			newObject = new Engine::TObjectParticle();
			break;
		case FOURCC_SOUND:
			newObject = new Engine::TObjectSound();
			break;
		default:
			std::cout << "STBFile::Deserialize(): Unknown object FourCC " << objectFourcc << "." << std::endl;
			break;
		}

		if (newObject == nullptr || !newObject->Deserialize(stream))
		{
			std::cout << "STBFile::Deserialize(): Unable to deserialize actor with FourCC " << objectFourcc << "." << std::endl;

			stream->seek(nextObjectOffset);
			continue;
		}

		mObjects.push_back(newObject);
		stream->seek(nextObjectOffset);
	}

	return true;
} // STBFile::Deserialize

bool JStudio::IO::STBFile::Serialize(bStream::CStream* stream)
{
	return true;
} // STBFile::Serialize
