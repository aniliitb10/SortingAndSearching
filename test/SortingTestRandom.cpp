#include "../lib/Quick3Way.h"
#include "../lib/Quick3WayString.h"
#include "Util.h"

#include <gtest/gtest.h>
#include <algorithm>
#include <random>

// Same random strings strings will be used for all sorts
static const Util::RandomGen randomGen {Util::readFile("/home/anil/CLionProjects/SortingAndSearching/test/wordlist.txt")};

struct StdSortTestRandom : public ::testing::Test
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
  Quick3Way::sort(_words);
}

struct Quick3WayStringTestRandom : public ::testing::Test
{
  List _words = randomGen.getRandomizedList();
};

TEST_F(Quick3WayStringTestRandom, PerfTest)
{
  Quick3WayString::sort(_words);
}

