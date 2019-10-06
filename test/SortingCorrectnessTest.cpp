#include "../lib/sorting/Quick3WayVector.h"
#include "../lib/sorting/Quick3WayStringVector.h"
#include "../lib/sorting/Quick3Way.h"
#include "../lib/sorting/QuickSort.h"
#include "../lib/sorting/MergeSort.h"
#include "../lib/sorting/InsertionSort.h"
#include "../lib/sorting/Util.h"
#include "../lib/sorting/CountingSort.h"

#include "Util.h"

#include <gtest/gtest.h>
#include <algorithm>
#include <random>

struct SortingCorrectnessTest : public ::testing::Test
{
  const List _toSort = Util::readFile("../test/nums.txt");
};

TEST_F(SortingCorrectnessTest, StdSort)
{
  auto toSortCopy = _toSort;
  std::sort(std::begin(toSortCopy), std::end(toSortCopy));
  EXPECT_TRUE(std::is_sorted(std::cbegin(toSortCopy), std::cend(toSortCopy)));
}

TEST_F(SortingCorrectnessTest, MyQuickSort)
{
  auto toSortCopy = _toSort;
  QuickSort::sort(std::begin(toSortCopy), std::end(toSortCopy));
  EXPECT_TRUE(std::is_sorted(std::cbegin(toSortCopy), std::cend(toSortCopy)));
}

TEST_F(SortingCorrectnessTest, MyQuick3WaySort)
{
  auto toSortCopy = _toSort;
  Quick3Way::sort(std::begin(toSortCopy), std::end(toSortCopy));
  EXPECT_TRUE(std::is_sorted(std::cbegin(toSortCopy), std::cend(toSortCopy)));
}

TEST_F(SortingCorrectnessTest, MyMergeSort)
{
  auto toSortCopy = _toSort;
  MergeSort::sort(std::begin(toSortCopy), std::end(toSortCopy));
  EXPECT_TRUE(std::is_sorted(std::cbegin(toSortCopy), std::cend(toSortCopy)));
}

TEST_F(SortingCorrectnessTest, MyQuick3WayStringSort)
{
  auto toSortCopy = _toSort;
  Quick3WayStringVector::sort(toSortCopy);
  EXPECT_TRUE(std::is_sorted(std::cbegin(toSortCopy), std::cend(toSortCopy)));
}

TEST_F(SortingCorrectnessTest, MyInsertionSort10K)
{
  // as it has n2 runtime complexity, reducing the input size to just 10k
  auto toSortCopy = decltype(_toSort) {std::begin(_toSort), std::next(std::begin(_toSort), 10'000)};
  InsertionSort::sort(std::begin(toSortCopy), std::end(toSortCopy));
  EXPECT_TRUE(std::is_sorted(std::cbegin(toSortCopy), std::cend(toSortCopy)));
}

TEST_F(SortingCorrectnessTest, CountingSortTest)
{
  std::vector<size_t> numbers{};
  constexpr size_t max_num{10'000};
  Util::randomNumGenerator(std::back_inserter(numbers), 1'000'000ul, 0ul, max_num);
  EXPECT_FALSE(std::is_sorted(std::cbegin(numbers), std::cend(numbers)));
  CountingSort::sort(std::begin(numbers), std::end(numbers), max_num);
  EXPECT_TRUE(std::is_sorted(std::cbegin(numbers), std::cend(numbers)));
}
