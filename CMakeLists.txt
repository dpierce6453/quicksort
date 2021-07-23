cmake_minimum_required(VERSION 3.19)
include(FetchContent)

project(quicksort)

set(CMAKE_CXX_STANDARD 20)

add_executable(quicksort main.cpp)

add_subdirectory(Tests)

add_library(quicksortlibrary quicksort.cpp)

enable_testing()