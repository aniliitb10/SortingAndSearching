#include <gtest/gtest.h>
#include <benchmark/benchmark.h>
#include <fstream>

int main(int argc_, char** argv_)
{

  ::benchmark::Initialize(&argc_, argv_);
    if (::benchmark::ReportUnrecognizedArguments(argc_, argv_)) return 1;
    ::benchmark::RunSpecifiedBenchmarks();

  testing::InitGoogleTest(&argc_, argv_);
  return RUN_ALL_TESTS();
}