#include <benchmark/benchmark.h>
#include "../lib/QuickSort.h"
#include "../lib/Quick3Way.h"
#include "../lib/Quick3WayStringVector.h"
#include "../lib/Quick3WayVector.h"
#include "../lib/MergeSort.h"
#include "../lib/Util.h"

#include "Util.h"
#include <algorithm>

struct SortingBenchmarkSortedInput : public benchmark::Fixture
{
  List _strs = Util::readFile("/home/anil/CLionProjects/SortingAndSearching/test/words.txt");
};

BENCHMARK_F(SortingBenchmarkSortedInput, StdSortTest)(benchmark::State& state)
{
  // setup
  auto toSort = _strs;

  // testing
  for (auto _ : state)
  {
    std::sort(std::begin(toSort), std::end(toSort));
  }
}

BENCHMARK_F(SortingBenchmarkSortedInput, MyQuickSortTest)(benchmark::State& state)
{
  // setup
  auto toSort = _strs;

  // testing
  for (auto _ : state)
  {
    QuickSort::sort(std::begin(toSort), std::end(toSort));
  }
}

BENCHMARK_F(SortingBenchmarkSortedInput, MyQuick3WayTest)(benchmark::State& state)
{
  // setup
  auto toSort = _strs;

  // testing
  for (auto _ : state)
  {
    Quick3Way::sort(std::begin(toSort), std::end(toSort));
  }
}

BENCHMARK_F(SortingBenchmarkSortedInput, MergeSortTest)(benchmark::State& state)
{
  // setup
  auto toSort = _strs;

  // testing
  for (auto _ : state)
  {
    MergeSort::sort(std::begin(toSort), std::end(toSort));
  }
}

BENCHMARK_F(SortingBenchmarkSortedInput, Quick3WayStringVectorTest)(benchmark::State& state)
{
  // setup
  auto toSort = _strs;

  // testing
  for (auto _ : state)
  {
    Quick3WayStringVector::sort(toSort);
  }
}