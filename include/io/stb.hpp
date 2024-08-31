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
		class TDirector;
		class TFunctionValue;
	} // namespace Engine

	namespace IO
	{
		class STBFile
		{
			// Sequence entities that were read from the file, or are to be written to file.
			std::vector<Engine::TDirector*> mDirectors;
			// Function values that were read from the file, or are to be written to file.
			std::vector<Engine::TFunctionValue*> mFunctionValues;

		public:
			STBFile() { }
			virtual ~STBFile() { }

			/// <summary>
			/// Provides the sequence entities read from the file when Deserialize() was called.
			/// </summary>
			/// <returns>Vector containing the sequence entities read from the file.</returns>
			std::vector<Engine::TDirector*> GetObjects() { return mDirectors; }
			/// <summary>
			/// Provides the function values read from the file when Deserialize() was called.
			/// </summary>
			/// <returns>Vector containing the function values read from the file.</returns>
			std::vector<Engine::TFunctionValue*> GetFunctionValues() { return mFunctionValues; }

			/// <summary>
			/// Sets the sequence entities to be written to file when Serialize() is called.
			/// </summary>
			/// <param name="objs">Vector of sequence objects to be written to file.</param>
			void SetObjects(std::vector<Engine::TDirector*>& dirs) { mDirectors = dirs; }
			/// <summary>
			/// Sets the function values to be written to file when Serialize() is called.
			/// </summary>
			/// <param name="fvs">Vector of function values to be written to file.</param>
			void SetFunctionValues(std::vector<Engine::TFunctionValue*>& fvs) { mFunctionValues = fvs; }

			/// <summary>
			/// Reads the objects and function values from the given data stream. Use GetObjects() and GetFunctionValues() to access the result of the read.
			/// </summary>
			/// <param name="stream">Data stream to read the file data from.</param>
			/// <returns>True if the read succeeded, false if not.</returns>
			bool Deserialize(bStream::CStream* stream);
			/// <summary>
			/// Writes objects and function values to the given data stream. Use SetObjects() and SetFunctionValues() to indicate what data to write.
			/// </summary>
			/// <param name="stream">Data stream to write the file data to.</param>
			/// <returns>True if the write succeeded, false if not.</returns>
			bool Serialize(bStream::CStream* stream);
		};
	} // namespace IO
} // namespace JStudio
