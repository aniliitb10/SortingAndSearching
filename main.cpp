#include <benchmark/benchmark.h>
#include <gtest/gtest.h>

// Custom main function that initializes both Google Test and Google Benchmark
int main(int argc, char** argv) {
    // Initialize Google Test
    ::testing::InitGoogleTest(&argc, argv);
    
    // Run the tests
    int testResult = RUN_ALL_TESTS();
    
    // Initialize Google Benchmark
    ::benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
    
    // Run the benchmarks
    ::benchmark::RunSpecifiedBenchmarks();
    
    // Return the test result
    return testResult;
}