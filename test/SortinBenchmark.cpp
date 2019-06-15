#include <benchmark/benchmark.h>
#include "../lib/QuickSort.h"
#include "../lib/Quick3Way.h"
#include "../lib/Quick3WayStringVector.h"
#include "../lib/Quick3WayVector.h"
#include "../lib/MergeSort.h"
#include "../lib/InsertionSort.h"
#include "../lib/Util.h"

#include "Util.h"
#include <algorithm>

struct SortingBenchmark : public benchmark::Fixture
{
  // file containing random numbers, to be treated as list of strings
  // It has 9999936/10000000 unique numbers (long int)
  List _strs = Util::readFile("/home/anil/CLionProjects/SortingAndSearching/test/nums.txt");
};

BENCHMARK_F(SortingBenchmark, StdSortTest)(benchmark::State& state)
{
  // setup
  auto toSort = _strs;

  // testing
  for (auto _ : state)
  {
    std::sort(std::begin(toSort), std::end(toSort));
  }
}

BENCHMARK_F(SortingBenchmark, MyQuickSortTest)(benchmark::State& state)
{
  // setup
  auto toSort = _strs;

  // testing
  for (auto _ : state)
  {
    QuickSort::sort(std::begin(toSort), std::end(toSort));
  }
}

BENCHMARK_F(SortingBenchmark, MyQuick3WayTest)(benchmark::State& state)
{
  // setup
  auto toSort = _strs;

  // testing
  for (auto _ : state)
  {
    Quick3Way::sort(std::begin(toSort), std::end(toSort));
  }
}

BENCHMARK_F(SortingBenchmark, MergeSortTest)(benchmark::State& state)
{
  // setup
  auto toSort = _strs;

  // testing
  for (auto _ : state)
  {
    MergeSort::sort(std::begin(toSort), std::end(toSort));
  }
}

BENCHMARK_F(SortingBenchmark, Quick3WayStringVectorTest)(benchmark::State& state)
{
  // setup
  auto toSort = _strs;

  // testing
  for (auto _ : state)
  {
    Quick3WayStringVector::sort(toSort);
  }
}