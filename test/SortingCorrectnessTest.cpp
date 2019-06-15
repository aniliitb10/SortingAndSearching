#include "../lib/Quick3WayVector.h"
#include "../lib/Quick3WayStringVector.h"
#include "../lib/Quick3Way.h"
#include "../lib/QuickSort.h"
#include "../lib/MergeSort.h"
#include "../lib/InsertionSort.h"
#include "../lib/Util.h"

#include "Util.h"

#include <gtest/gtest.h>
#include <algorithm>
#include <random>

struct SortingCorrectnessTest : public ::testing::Test
{
  List _toSort = Util::readFile("/home/anil/CLionProjects/SortingAndSearching/test/nums.txt");
};

TEST_F(SortingCorrectnessTest, StdSort)
{
  auto toSortCopy = _toSort;
  std::sort(std::begin(toSortCopy), std::end(toSortCopy));
  EXPECT_TRUE(isSorted(std::begin(toSortCopy), std::end(toSortCopy)));
}

TEST_F(SortingCorrectnessTest, MyQuickSort)
{
  auto toSortCopy = _toSort;
  QuickSort::sort(std::begin(toSortCopy), std::end(toSortCopy));
  EXPECT_TRUE(isSorted(std::begin(toSortCopy), std::end(toSortCopy)));
}

TEST_F(SortingCorrectnessTest, MyQuick3WaySort)
{
  auto toSortCopy = _toSort;
  Quick3Way::sort(std::begin(toSortCopy), std::end(toSortCopy));
  EXPECT_TRUE(isSorted(std::begin(toSortCopy), std::end(toSortCopy)));
}

TEST_F(SortingCorrectnessTest, MyMergeSort)
{
  auto toSortCopy = _toSort;
  MergeSort::sort(std::begin(toSortCopy), std::end(toSortCopy));
  EXPECT_TRUE(isSorted(std::begin(toSortCopy), std::end(toSortCopy)));
}

TEST_F(SortingCorrectnessTest, MyQuick3WayStringSort)
{
  auto toSortCopy = _toSort;
  Quick3WayStringVector::sort(toSortCopy);
  EXPECT_TRUE(isSorted(std::begin(toSortCopy), std::end(toSortCopy)));
}

TEST_F(SortingCorrectnessTest, MyInsertionSort10K)
{
  // as it has n2 runtime complexity, reducing the input size to just 10k
  decltype(_toSort) toSortCopy{std::begin(_toSort), std::next(std::begin(_toSort), 10'000)};
  InsertionSort::sort(std::begin(toSortCopy), std::end(toSortCopy));
  EXPECT_TRUE(isSorted(std::begin(toSortCopy), std::end(toSortCopy)));
}
