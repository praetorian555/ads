#pragma once

#include <iterator>
#include <string_view>

namespace ads
{

template <typename BidirectionIt, typename Compare = std::less<typename BidirectionIt::value_type>>
void InsertionSort(BidirectionIt Begin, BidirectionIt End)
{
    Compare Comp;
    for (BidirectionIt i = std::next(Begin); i != End; ++i)
    {
        for (BidirectionIt j = i; j != Begin && Comp(*j, *prev(j)); j = prev(j))
        {
            std::swap(*j, *std::prev(j));
        }
    }
}

}  // namespace ads
