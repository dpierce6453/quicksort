#include <iostream>
#include <list>
#include "parallel_quick_sort.h"
#include <benchmark/benchmark.h>
#include <random>


void print_results(const char *const tag, const std::list<double> &sorted,
                   std::chrono::high_resolution_clock::time_point startTime,
                   std::chrono::high_resolution_clock::time_point endTime) {
  printf("%s: Lowest: %g Highest: %g Time: %fms\n", tag, sorted.front(),
         sorted.back(),
         std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(
             endTime - startTime)
             .count());
}

int main() {

  // generate some random doubles:
  printf("Testing with %zu doubles...\n", 4000);
  std::random_device rd;
  std::list<double> doubles(4000);
  for (auto &d : doubles) {
    d = static_cast<double>(rd());
  }

  for (int i = 0; i < 5; ++i) {
    std::list<double> sorted(doubles);
    const auto startTime = std::chrono::high_resolution_clock::now();
    // same sort call as above, but with par_unseq:
    parallel_quick_sort(doubles);
    const auto endTime = std::chrono::high_resolution_clock::now();
    // in our output, note that these are the parallel results:
    print_results("Parallel STL", sorted, startTime, endTime);
  }

  for (int i = 0; i < 5; ++i) {
    std::list<double> sorted(doubles);
    const auto startTime = std::chrono::high_resolution_clock::now();
    // same sort call as above, but with par_unseq:
    sequential_quick_sort(doubles);
    const auto endTime = std::chrono::high_resolution_clock::now();
    // in our output, note that these are the parallel results:
    print_results("Sequential STL", sorted, startTime, endTime);
  }
}
//static void BM_sequential_quick_sort(benchmark::State& state) {
//
//  std::random_device rd;
//  std::list<double> doubles(20000);
//  for (auto &d : doubles) {
//    d = static_cast<double>(rd());
//  }
//
//    for (auto _ : state)
//        std::list<double> answer = sequential_quick_sort(doubles);
//}
//
//static void BM_parallel_quick_sort(benchmark::State& state) {
//
//  std::random_device rd;
//  std::list<double> doubles(20000);
//  for (auto &d : doubles) {
//    d = static_cast<double>(rd());
//  }
//
//    for (auto _ : state)
//        std::list<double> answer = parallel_quick_sort(doubles);
//}
//
//
//BENCHMARK(BM_sequential_quick_sort);
//BENCHMARK(BM_parallel_quick_sort);
//
//BENCHMARK_MAIN();
