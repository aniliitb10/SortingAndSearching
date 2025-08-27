#include <benchmark/benchmark.h>
#include "../lib/sorting/QuickSort.h"
#include "../lib/sorting/Quick3Way.h"
#include "../lib/sorting/Quick3WayStringVector.h"
#include "../lib/sorting/Quick3WayVector.h"
#include "../lib/sorting/MergeSort.h"
#include "../lib/sorting/Util.h"
#include "../lib/sorting/CountingSort.h"

#include "Util.h"
#include <algorithm>
#include <vector>

struct SortingBenchmark : public benchmark::Fixture {
    // file containing random numbers, to be treated as list of strings
    // It has 9999936/10000000 unique numbers (long int)
    const List _strs = Util::readFile("../test/nums.txt");

    // this data is specially for counting sort
    const std::vector<size_t> _numbers = Util::readFile<size_t>("../test/800000numbers0To1000000.txt");
};

BENCHMARK_F(SortingBenchmark, StdSortTest)(benchmark::State &state) {
    // setup
    auto toSort = _strs;

    // testing
    for (auto _: state) {
        std::sort(std::begin(toSort), std::end(toSort));
    }
}

BENCHMARK_F(SortingBenchmark, MyQuickSortTest)(benchmark::State &state) {
    // setup
    auto toSort = _strs;

    // testing
    for (auto _: state) {
        QuickSort::sort(std::begin(toSort), std::end(toSort));
    }
}

BENCHMARK_F(SortingBenchmark, MyQuick3WayTest)(benchmark::State &state) {
    // setup
    auto toSort = _strs;

    // testing
    for (auto _: state) {
        Quick3Way::sort(std::begin(toSort), std::end(toSort));
    }
}

BENCHMARK_F(SortingBenchmark, MergeSortTest)(benchmark::State &state) {
    // setup
    auto toSort = _strs;

    // testing
    for (auto _: state) {
        MergeSort::sort(std::begin(toSort), std::end(toSort));
    }
}

BENCHMARK_F(SortingBenchmark, Quick3WayStringVectorTest)(benchmark::State &state) {
    // setup
    auto toSort = _strs;

    // testing
    for (auto _: state) {
        Quick3WayStringVector::sort(toSort);
    }
}

BENCHMARK_F(SortingBenchmark, CountingSortTest)(benchmark::State &state) {
    // setup
    auto toSort = _numbers;
    auto max_num = *std::max_element(std::cbegin(toSort), std::cend(toSort));

    // testing
    for (auto _: state) {
        CountingSort::sort(std::begin(toSort), std::end(toSort), max_num);
    }
}

BENCHMARK_F(SortingBenchmark, StdSortWithCountingSortSampleTest)(benchmark::State &state) {
    // setup
    auto toSort = _numbers;

    // testing
    for (auto _: state) {
        std::sort(std::begin(toSort), std::end(toSort));
    }
}
