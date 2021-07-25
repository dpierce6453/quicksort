cmake_minimum_required(VERSION 3.19)
include(FetchContent)

set(This quicksorttests)
project(${This})

set(CMAKE_CXX_STANDARD 20)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable( ${This}
  SortTests.cpp
  ${CMAKE_SOURCE_DIR}//parallel_quick_sort.h
)

target_include_directories(${This} SYSTEM PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
)
target_link_libraries(
  ${This}
  gtest_main
  quicksortlibrary
)

include(GoogleTest)
gtest_discover_tests(${This})