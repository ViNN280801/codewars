#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <random>
#include <unistd.h>
#include <vector>

#include <gtest/gtest.h>

#ifndef N
  #define N 1'000'000
#endif

#ifndef N_arr
  #define N_arr 1'000
#endif

extern "C" {
  int double_it(int);
  int is_even(int);
  int abs_val(int);
  int max_of_two(int, int);
  int sum_array(int const*, int);
}

namespace {
  std::random_device                 _g_rd;
  std::mt19937                       _g_gen(_g_rd());
  std::uniform_int_distribution<int> _g_distr(-N, N);

  int _get_random_int() { return _g_distr(_g_gen); }
  int _get_random_int_par(int lower_bound, int upper_bound) // par -> parametrized
  {
    std::uniform_int_distribution<int> distr(lower_bound, upper_bound);
    return distr(_g_gen);
  }
  std::vector<int> _get_random_int_vector(int size) {
    std::vector<int> v;
    v.reserve(size);
    std::generate_n(std::back_inserter(v), size, _get_random_int);
    return v;
  }
} // anonymous namespace

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

TEST(NASMTestsOwnTasks, max_of_two_test)
{
  auto max_of_two_checker = [](int a, int b) { return std::max(a, b); };
  for (int i = -N; i < N; ++i)
  {
    int a = _get_random_int();
    int b = _get_random_int();

    EXPECT_TRUE(max_of_two(a, b) == max_of_two_checker(a, b));
  }
}

TEST(NASMTestsOwnTasks, sum_array_test)
{
  auto sum_array_checker = [](int const *arr, int n) {
    if ((arr == nullptr) || (n < 0)) return 0;
    return std::accumulate(arr, arr + n, 0);
  };

  // Edge case #1
  EXPECT_EQ(sum_array(nullptr, 7), sum_array_checker(nullptr, 15));
  EXPECT_EQ(sum_array(nullptr, 1), sum_array_checker(nullptr, 3));
  EXPECT_EQ(sum_array(nullptr, 0), sum_array_checker(nullptr, 8));
  EXPECT_EQ(sum_array(nullptr, 745), sum_array_checker(nullptr, 0));

  // Edge case #2
  std::vector edge2 = {1, 2, 3};
  EXPECT_EQ(sum_array(edge2.data(), -7), 0);
  EXPECT_EQ(sum_array(edge2.data(), -7), sum_array_checker(edge2.data(), -9));
  EXPECT_EQ(sum_array(edge2.data(), -3), sum_array_checker(edge2.data(), -3));

  // Default cases
  for (int arr_count = 0; arr_count < N; ++arr_count)
  {
    auto v = _get_random_int_vector(_get_random_int_par(0, N_arr));
    EXPECT_EQ(sum_array(v.data(), v.size()), sum_array_checker(v.data(), v.size()));
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

