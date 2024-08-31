#pragma once

#include "types.h"
#include "key.hpp"

namespace JStudio
{
	namespace Engine
	{
		class TTrack
		{
			std::vector<TKey> mKeys;

		public:
			TTrack() { }
			virtual ~TTrack() { }

			void AddKey(const float& value, const uint32_t& time, const EUpdateType& updateType);

			void SortKeys();

			bool TryGetKey(const uint32_t& time, TKey& outKey);
		};
	} // namespace Engine
} // namespace JStudio
