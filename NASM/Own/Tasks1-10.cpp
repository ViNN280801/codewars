#include <algorithm>
#include <iterator>
#include <cstring>
#include <numeric>
#include <random>
#include <vector>

#include <gtest/gtest.h>

#ifndef N
  #define N 1'000'000
#endif

#ifndef N_arr // Size of array
  #define N_arr 100'000
#endif

#ifndef N_iterations // Number of iterations in loops
  #define N_iterations 3'000
#endif

extern "C" {
  int double_it(int);
  int is_even(int);
  int abs_val(int);
  int max_of_two(int, int);
  int sum_array(int const*, int);
  int count_char(char const *, char);
  int is_power_of_two(unsigned int);
  long long fib(int);
  size_t str_len(char const *str);
  int *make_squares(int n, size_t *out_size);
}

namespace {
  std::random_device                 _g_rd;
  std::mt19937                       _g_gen(_g_rd());

  template <typename T = int>
  int _get_random() {
    std::uniform_int_distribution<T> distr(-N, N);
    return distr(_g_gen);
  }

  template <typename T = int>
  int _get_random_par(T lower_bound, T upper_bound) // par -> parametrized
  {
    std::uniform_int_distribution<T> distr(lower_bound, upper_bound);
    return distr(_g_gen);
  }

  template <typename T = int>
  std::vector<T> _get_random_vector(int size) {
    std::vector<T> v;
    v.reserve(size);
    std::generate_n(std::back_inserter(v), size, _get_random<T>);
    return v;
  }

  template <typename T = int>
  std::vector<T> _get_random_vector_par(int size, T lower_bound, T upper_bound) {
    std::vector<T> v;
    v.reserve(size);
    std::uniform_int_distribution<T> distr(lower_bound, upper_bound);
    std::generate_n(std::back_inserter(v), size, [&](){ return distr(_g_gen); });
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
    int a = _get_random();
    int b = _get_random();

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
  for (int iteration = 0; iteration < N_iterations; ++iteration)
  {
    auto v = _get_random_vector(_get_random_par(0, N_arr));
    EXPECT_EQ(sum_array(v.data(), v.size()), sum_array_checker(v.data(), v.size()));
  }
}

TEST(NASMTestsOwnTasks, count_char)
{
  auto count_char_checker = [](char const *s, char c){
    // return static_cast<int>(std::count_if(s, s + strlen(s), [c](char a){ return a == c; }));
    int count = 0;
    while (*s != 0) if (*(s++) == c) ++count;
    return count;
  };

  for (int iteration = 0; iteration < N_iterations; ++iteration)
  {
    int size = _get_random_par(0, N_arr);
    auto v = _get_random_vector_par<char>(size, 0x01, 0x7F);
    v.push_back('\0');
    char searching = static_cast<char>(_get_random_par(0x01, 0x7F));

    int test = count_char(v.data(), searching);
    int expected = count_char_checker(v.data(), searching);

    EXPECT_EQ(test, expected);
  }
}


TEST(NASMTestsOwnTasks, is_power_of_two_test)
{
  auto is_power_of_two_checker = [](unsigned int n) -> int  { return (n > 0) && ((n & (n - 1)) == 0); };
  for (int num = 0; num < N; ++num)
  {
    EXPECT_EQ(is_power_of_two(num), is_power_of_two_checker(num));
  }
}


TEST(NASMTestsOwnTasks, fib_test)
{
  using int64 = long long;
  auto fib_checker = [](int n) -> int64 {
    if (n <= 1) return n;

    int64 a    = 0;
    int64 b    = 1;
    int64 next = -1;

    for (decltype(n) i = 1; i <= n; ++i)
    {
      next = a + b;
      a    = b;
      b    = next;
    }
    return b;
  };

  for (int num = -N; num < 60; ++num)
  {
    EXPECT_EQ(fib(num), fib_checker(num));
  }
}

TEST(NASMTestsOwnTasks, str_len)
{
  auto str_len_checker = [](char const *str){
    std::size_t length = 0ULL;
    while (*(str++) != 0) ++length;
    return length;
  };
  for (int iteration = 0; iteration < N_iterations; ++iteration)
  {
    int size = _get_random_par(0, N_arr);
    auto v = _get_random_vector_par<char>(size, 0x01, 0x7F);
    v.push_back('\0');
    std::size_t test     = str_len(v.data());
    std::size_t expected = str_len_checker(v.data());

    std::size_t expectedlibfunc = std::strlen(v.data());

    EXPECT_EQ(expected, expectedlibfunc);
    EXPECT_EQ(test, expected);
    EXPECT_EQ(test, expectedlibfunc);
  }
}

TEST(NASMTestsOwnTasks, make_squares)
{
  auto make_squares_checker = [](int n, std::size_t *out_size) -> int* {
    if ((n <= 0) || (out_size == nullptr)) return nullptr;
    int *res = new int[n];
    if (res == nullptr) return nullptr;
    for (int i = 0; i < n; ++i) res[i] = (i + 1) * (i + 1);
    *out_size = n;
    return res;
  };
  for (int iteration = 0; iteration < N_iterations; ++iteration)
  {
    int size = _get_random_par(0, N_arr);
    auto v = _get_random_vector_par(size, -10'000, 10'000);

    std::size_t test_size = 0ULL;
    int *test             = make_squares(size, &test_size);

    std::size_t expected_size = 0ULL;
    int *expected             = make_squares_checker(size, &expected_size);

    EXPECT_EQ(test_size, expected_size);
    for (std::size_t i = 0ULL; i < test_size; ++i)
    {
      EXPECT_EQ(test[i], expected[i]);
    }

    free(test);
    delete[] expected;
 }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

