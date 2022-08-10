#include <gtest/gtest.h>

#include "ads/sort/insertionsort.h"

TEST(SortTests, InsertionSort)
{
	static constexpr int kTestSize = 1'000;
	std::vector<int> Arr(kTestSize);
	for (int i = 0; i < kTestSize; i++)
	{
		Arr[i] = kTestSize - i;
	}

	ads::InsertionSort(begin(Arr), end(Arr));

	for (int i = 0; i < kTestSize; i++)
	{
		EXPECT_EQ(Arr[i], i + 1);
	}
}