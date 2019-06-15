#include "../lib/Quick3WayVector.h"
#include "../lib/Quick3WayString.h"
#include "Util.h"

#include <gtest/gtest.h>
#include <algorithm>
#include <random>

// Same random strings strings will be used for all sorts
static const List words {Util::readFile("/home/anil/CLionProjects/SortingAndSearching/test/wordlist.txt")};

struct StdSortTestSorted : public ::testing::Test
{
  List _words = words;
};

TEST_F(StdSortTestSorted, PerfTest)
{
  std::sort(std::begin(_words), std::end(_words));
}

struct Quick3WayTestSorted : public ::testing::Test
{
  List _words = words;
};

TEST_F(Quick3WayTestSorted, PerfTest)
{
  Quick3WayVector::sort(_words);
}

struct Quick3WayStringTestSorted : public ::testing::Test
{
  List _words = words;
};

TEST_F(Quick3WayStringTestSorted, PerfTest)
{
  Quick3WayString::sort(_words);
}

