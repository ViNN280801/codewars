#include <limits>

#include <gtest/gtest.h>

#ifndef N
  #define N 1'000'000
#endif

extern "C" {
  int double_it(int n);
  int is_even(int n);
  int abs_val(int n);
}

TEST(NASMTestsOwnTasks, double_it_test)
{
  auto double_it_checker = [](int n) { return n * 2; };
  for (int num = -N; num < N; ++num)
  {
    EXPECT_TRUE(double_it(num) == double_it_checker(num));
  }
}

TEST(NASMTestsOwnTasks, is_even_test)
{
  auto is_even_checker = [](int n) { return !(n & 1); };
  for (int num = -N; num < N; ++num)
  {
    EXPECT_TRUE(is_even(num) == is_even_checker(num));
  }
}

TEST(NASMTestsOwnTasks, abs_val_test)
{
  auto abs_val_checker = [](int n) { return (n < 0) ? -n : n; };
  for (int num = -N; num < N; ++num)
  {
    EXPECT_TRUE(abs_val(num) == abs_val_checker(num));
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

