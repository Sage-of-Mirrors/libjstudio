#pragma once

#include "types.h"
#include "key.hpp"

#include <algorithm>

namespace JStudio
{
	namespace Engine
	{
		template<typename T>
		class TTrack
		{
			std::vector<TKey<T>> mKeys;

		public:
			TTrack() { }
			virtual ~TTrack() { }

			void AddKey(const T& value, uint32_t time)
			{
				mKeys.push_back(TKey<T>(value, time));
				SortKeys();
			}

			void SortKeys()
			{
				std::sort(mKeys.begin(), mKeys.end(), [](const TKey<T>& a, const TKey<T>& b) { return a.GetTime() < b.GetTime(); });
			}
		};
	} // namespace Engine
} // namespace JStudio
