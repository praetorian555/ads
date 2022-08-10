#pragma once

namespace ads
{

	template <typename ForwardIt>
	void InsertionSort(ForwardIt Begin, ForwardIt End)
	{
		for (ForwardIt i = next(Begin); i != End; ++i)
		{
			for (ForwardIt j = i; j != Begin && *j < *prev(j); j = prev(j))
			{
				std::swap(*j, *prev(j));
			}
		}
	}

}