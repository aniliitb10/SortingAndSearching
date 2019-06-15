#include "../lib/Quick3WayVector.h"
#include "../lib/Quick3WayString.h"
#include "../lib/Quick3Way.h"
#include "../lib/QuickSort.h"
#include "../lib/MergeSort.h"
#include "../lib/Util.h"

#include "Util.h"

#include <gtest/gtest.h>
#include <algorithm>
#include <random>

// Same random strings strings will be used for all sorts
//static const Util::RandomGen randomGen {Util::readFile("/home/anil/CLionProjects/SortingAndSearching/test/wordlist.txt")};

struct SortingCorrectnessTest : public ::testing::Test
{
  void SetUp() override
  {
    _toSort = random.getRandomizedList();
  }

  const Util::RandomGen random {Util::readFile("/home/anil/CLionProjects/SortingAndSearching/test/wordlist.txt")};
  List _toSort = random.getRandomizedList();
};

TEST_F(SortingCorrectnessTest, StdSort)
{
  std::sort(std::begin(_toSort), std::end(_toSort));
  EXPECT_TRUE(isSorted(std::begin(_toSort), std::end(_toSort)));
}

TEST_F(SortingCorrectnessTest, MyQuickSort)
{
  QuickSort::sort(std::begin(_toSort), std::end(_toSort));
  EXPECT_TRUE(isSorted(std::begin(_toSort), std::end(_toSort)));
}

TEST_F(SortingCorrectnessTest, MyQuick3WaySort)
{
  Quick3Way::sort(std::begin(_toSort), std::end(_toSort));
  EXPECT_TRUE(isSorted(std::begin(_toSort), std::end(_toSort)));
}

TEST_F(SortingCorrectnessTest, MyMergeSort)
{
  MergeSort::sort(std::begin(_toSort), std::end(_toSort));
  EXPECT_TRUE(isSorted(std::begin(_toSort), std::end(_toSort)));
}

TEST_F(SortingCorrectnessTest, MyQuick3WayStringSort)
{
  Quick3WayString::sort(_toSort);
  EXPECT_TRUE(isSorted(std::begin(_toSort), std::end(_toSort)));
}


/*struct StdSortTestRandom : public ::testing::Test
{
  List _words = randomGen.getRandomizedList();
};

TEST_F(StdSortTestRandom, PerfTest)
{
  std::sort(std::begin(_words), std::end(_words));
}

struct Quick3WayTestRandom : public ::testing::Test
{
  List _words = randomGen.getRandomizedList();
};

TEST_F(Quick3WayTestRandom, PerfTest)
{
  Quick3WayVector::sort(_words);
}

struct Quick3WayStringTestRandom : public ::testing::Test
{
  List _words = randomGen.getRandomizedList();
};

TEST_F(Quick3WayStringTestRandom, PerfTest)
{
  Quick3WayString::sort(_words);
}*/

