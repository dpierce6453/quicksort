cmake_minimum_required(VERSION 3.19)
include(FetchContent)

project(quicksorttests)

set(CMAKE_CXX_STANDARD 20)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  #GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
  GIT_TAG        release-1.11.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable( quicksorttests
  SortTests.cpp
)
target_link_libraries(
  quicksorttests
  gtest_main
  quicksortlibrary
)

include(GoogleTest)
gtest_discover_tests(quicksorttests)