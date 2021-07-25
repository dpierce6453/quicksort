cmake_minimum_required(VERSION 3.19)
include(FetchContent)

set(This quicksort)
project(${This})

set(CMAKE_CXX_STANDARD 20)

FetchContent_Declare(
  googlebenchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG        v1.5.5
)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
set(BENCHMARK_ENABLE_TESTING OFF)
FetchContent_MakeAvailable(googlebenchmark)

add_executable(${This} main.cpp parallel_quick_sort.h)
target_link_libraries(${This} PUBLIC benchmark_main benchmark)

add_subdirectory(Tests)

add_library(quicksortlibrary quicksort.cpp)

enable_testing()