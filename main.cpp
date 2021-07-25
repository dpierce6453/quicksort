#include <iostream>
#include <list>
#include "parallel_quick_sort.h"
#include <benchmark/benchmark.h>
#include <random>

static void BM_sequential_quick_sort(benchmark::State& state) {

  std::random_device rd;
  std::list<double> doubles(20000);
  for (auto &d : doubles) {
    d = static_cast<double>(rd());
  }

    for (auto _ : state)
        std::list<double> answer = sequential_quick_sort(doubles);
}

static void BM_parallel_quick_sort(benchmark::State& state) {

  std::random_device rd;
  std::list<double> doubles(20000);
  for (auto &d : doubles) {
    d = static_cast<double>(rd());
  }

    for (auto _ : state)
        std::list<double> answer = parallel_quick_sort(doubles);
}


BENCHMARK(BM_sequential_quick_sort);
BENCHMARK(BM_parallel_quick_sort);

BENCHMARK_MAIN();
