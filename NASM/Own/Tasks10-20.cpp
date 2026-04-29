#include <numeric>
#include <type_traits>
#include <random>

#include <gtest/gtest.h>

#ifndef N
  #define N 1'000'000
#endif

#ifndef N_iterations
  #define N_iterations 100'000
#endif

extern "C" {
  int gcd(int a, int b);
}

namespace {
  std::random_device _g_rd;
  std::mt19937       _g_gen(_g_rd());

  template <typename T = int>
  int _get_random() {
    static_assert(std::is_integral_v<T>, "T must be integral");
    std::uniform_int_distribution<T> distr(-N, N);
    return distr(_g_gen);
  }

  template <typename T = int>
  int _get_random_par(T lower_bound, T upper_bound)
  {
    static_assert(std::is_integral_v<T>, "T must be integral");
    std::uniform_int_distribution<T> distr(lower_bound, upper_bound);
    return distr(_g_gen);
  }
} // anonymous namespace

TEST(NASMOwnTests, gcd_test) {
  auto gcd_checker = [](int a, int b) {
    return std::gcd(a, b);
  };
  for (int i = 0; i < N_iterations; ++i) {
    int a = _get_random();
    int b = _get_random();

    auto gcd_orig_result    = gcd(a, b);
    auto gdc_checker_result = gcd_checker(a, b);

    EXPECT_EQ(gcd_orig_result, gdc_checker_result);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(__builtin_addressof(argc), argv);
  return RUN_ALL_TESTS();
}

