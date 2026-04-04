#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <type_traits>
#include <iterator>
#include <unordered_set>
#include <map>
#include <sstream>

class SumOfDivided
{
  template <typename Range>
  using range_value_t = typename std::iterator_traits<decltype(std::begin(std::declval<Range&>()))>::value_type;

  using number_value_type       = long long;
  using prime_value_type        = long long;
  using prime_factor_value_type = unsigned long long;

  using sum_value_type = long long;

  using prime_factors_set    = std::unordered_set<prime_factor_value_type>;
  using prime_factor_sum_map = std::map<prime_factor_value_type, sum_value_type>;

public:
    template <typename Range,
             typename RangeValueT = range_value_t<Range>,
             std::enable_if_t<
               std::is_integral_v<RangeValueT> and
               std::is_signed_v<RangeValueT> and not
               std::is_same_v<RangeValueT, bool>,
             int> = 0>
    static std::string sumOfDivided(Range &lst)
    {
      // 1. If there is no elems -> just return empty string
      //    Time complexity  [1]: O(1) -> best case
      //    Space complexity [1]: O(1) -> best case
      if (lst.empty()) return "";

      // 2. If all the elems are 0 -> also return empty string, because 0 has no factors
      //    Time complexity  [2]: O(n) -> middle case
      //    Space complexity [2]: O(1) -> middle case
      if (std::all_of(lst.begin(), lst.end(), [](RangeValueT elem) { return elem == 0; } )) return "";

      // 3. Iterating over the elements from the input and iterating by all the prime factors of this element
      //    Time complexity  [3]: O(n)*O(sqrt n)*O(log m) -> worst case step 1, where n - number of elems in input, k - number of prime numbers of specific elem
      //    Space complexity [3]: O(m) -> worst case step 1, where m - count of numbers in resulting map
      prime_factor_sum_map factorsSumMap;
      for (auto num : lst)
      {
        // _getPrimeFactors:
        //   Time complexity  [3.1]: O(sqrt num)
        //   Space complexity [3.1]: O(1)
        auto const &primeFactors = _getPrimeFactors(static_cast<prime_factor_value_type>(std::abs(num)));
        for (auto factor : primeFactors)
        {
          // Time complexity  [3.1.1]: O(log m)
          // Space complexity [3.1.1]: O(1)
          factorsSumMap[factor] += num;
        }
      }

      // 4. Iterating over the map to compose string via sstream
      //    Time complexity  [4]: O(m) -> worst case step 2
      //    Space complexity [4]: O(1) -> worst case step 2
      std::stringstream ss;
      for (auto const &factor_sum : factorsSumMap)
      {
        ss << '(' << factor_sum.first << ' ' << factor_sum.second << ')';
      }
      return ss.str();

      // Resulting complexities (for average case; best, midd and worst are indicated in the code) = ∑complexities in each step
      // Time complexity:  O(1)+O(n)+O(n)*O(sqrt n)*O(log m)+O(m) => O(n)+O(n*sqrt(n)*log(m))+O(m)
      // Space complexity: O(1)+O(1)+O(m)+O(1)                    => O(m)
    }

private:
    static prime_factors_set _getPrimeFactors(prime_value_type number)
    {
      if (number == 0) return {};

      prime_factors_set factors;
      for (prime_factor_value_type factor{2}; factor <= static_cast<prime_factor_value_type>(std::sqrt(number)); ++factor)
      {
        while (number % factor == 0)
        {
          factors.insert(factor);
          number /= factor;
        }
      }

      // If there is no prime factors except 1 and the number itself
      if (number > 1) factors.insert(number);
      return factors;
    }
};

#include <cassert>
#include <vector>
#include <iostream>

int main()
{
  std::vector v = {12, 15};
  std::string result = SumOfDivided::sumOfDivided(v);
  std::string expected = "(2 12)(3 27)(5 15)";
  assert(result == expected);

  v = {};
  result = SumOfDivided::sumOfDivided(v);
  expected = "";
  assert(result == expected);

  v = {15, 30, -45};
  result = SumOfDivided::sumOfDivided(v);
  expected = "(2 30)(3 0)(5 0)";
  assert(result == expected);

  return EXIT_SUCCESS;
}

