//
// Created by Dan on 7/22/2021.
//

#include <gtest/gtest.h>
#include <list>

#include <parallel_quick_sort.h>
#include <random>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(QuickSortTests, FirstTest)
{
    std::list<int> unsortedlist = {8, 3, 12, 9, 5, 6, 11, 1, 13, 2};
    std::list<int> sortedlist = {1,2,3,5,6,8,9,11,12,13};

    std::list<int> answer = sequential_quick_sort(unsortedlist);
    ASSERT_TRUE(std::equal(sortedlist.begin(), sortedlist.end(), answer.begin()));
}

TEST(QuickSortTests, LongTest)
{
    std::random_device rd;
    std::list<double> doubles(20000);
    for (auto &d : doubles) {
        d = static_cast<double>(rd());
    }
    auto seq = sequential_quick_sort(doubles);
    auto par = parallel_quick_sort(doubles);
    ASSERT_TRUE(std::equal(seq.begin(), seq.end(), par.begin()));
}