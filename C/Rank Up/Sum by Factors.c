#include <stdlib.h> // for mem management and sorting
#include <stdbool.h> // for boolean type
#include <stddef.h> // for `size_t`
#include <tgmath.h> // for `abs` and `sqrt`
#include <stdio.h> // for `sprintf`
#include <limits.h> // for `ULLONG_MAX`
#include <string.h> // for cstr concat

typedef struct {
  unsigned long factor;
  long long sum;
} factor_sum_t;

// Time complexity:
//   - worst: O(n), where n - size of elements
//   - best : O(1), if factor to find is 1st element
// Space complexity: O(1)
size_t find_factor(factor_sum_t const *arr, size_t size, unsigned long factor)
{
  if (arr == NULL || size == 0ULL) return ULLONG_MAX;
  for (size_t i = 0ULL; i < size; ++i)
    if (arr[i].factor == factor) return i;
  return ULLONG_MAX; // ULL_MAX
}

// Time complexity: O(1)
// Space complexity: O(1)
int compare_factors(void const *a, void const *b)
{
  unsigned long arg1 = *(unsigned long const *)a;
  unsigned long arg2 = *(unsigned long const *)b;

  if (arg1 < arg2) return -1;
  if (arg1 > arg2) return 1;
  return 0;
}

// Time complexity : O(1)+O(k)+O(1)+O(k) = 2*O(1)+2*O(k) = O(k), where k - length of formatted string
// Space complexity: O(1)+O(1)+O(needed bytes for str)+O(1) = O(l), where l - needed bytes for resulting string
char const *factor_sum_t_to_string(factor_sum_t const *arr, size_t arr_size)
{
  // 1. Checking input parameters
  //    Time complexity  [1]: O(1) -> best case
  //    Space complexity [1]: O(1) -> best case
  if (arr == NULL || arr_size == 0ULL) return "";

  // 2. Iterating over the elements of array of structures to find exact number of elements for memory allocation
  //    Time complexity  [2]: O(k), where k - length of formatted string
  //    Space complexity [2]: O(1)
  int needed = 0;
  for (size_t i = 0ULL; i < arr_size; ++i)
  {
    needed += snprintf(NULL, 0, "(%lu %lld)", arr[i].factor, arr[i].sum);
  }
  ++needed;

  // 3. Allocating exact mem for string (including '\0')
  //    Time complexity  [2]: O(1)
  //    Space complexity [2]: O(needed bytes for str)
  char *result = (char*)malloc((size_t)needed * sizeof(char)); // sizeof(char) we can omit, but I leave it here for clarity
  if (result == NULL) return "";
  // result[needed] = '\0'; // no need in '\0', because `sprintf` will do it

  // 4. Composing the string
  //    Time complexity  [4]: O(k), where k - length f formatting string
  //    Space complexity [4]: O(1) (was allocated in [3])
  int offset = 0;
  for (size_t i = 0ULL; i < arr_size; ++i)
  {
    offset += sprintf(result + offset, "(%lu %lld)", arr[i].factor, arr[i].sum);
  }
  return result;
}

// Time complexity : O(1)
// Space complexity: O(1)
bool is_null(int num) { return num == 0; }

// Time complexity:
//   - worst: O(n), where n - count of elems in array
//   - midd : O(m), where m - count of elems while early return
//   - best : O(1) - if checking 1 not passed or first elem of arr is not correspond to predicate
// Space complexity:
//   - worst|midd|best: O(1) - there is no allocating additional space for this function
bool all_of(const int* const values, size_t values_size, bool (*predicate)(int))
{
  // 1. If values is NULL or values_size is 0 -> returning `false`
  //    Time complexity  [1]: O(1) -> best case
  //    Space complexity [1]: O(1) -> best case
  if (values == NULL || values_size == 0) return false;

  // 2. Iterating over the values
  //    Time complexity  [2]: O(n) -> worst case, where n - count of elements
  //    Space complexity [2]: O(1) -> wors case
  for (size_t i = 0UL; i < values_size; ++i)
  {
    // 2.1. Early return if some value is not correspond the predicate
    //      Time complexity  [2.1]: O(m) -> midd case, where m - count of elements while early return
    //      Space complexity [2.1]: O(1) -> midd case
    if (!predicate(values[i])) return false;
  }

  // 3. If all the elems are correspond to predicate
  return true;
}

// Time complexity : O(1)+O(sqrt num)*O(X)+O(sqrt num)*O(X) = O(1)+2*O(sqrt num)*O(X) = O(sqrt num)*O(X)
// Space complexity: O(1)+O(1)+O(prime factors count) = O(prime factors count)
void get_prime_factors(int number, unsigned long **out_factors, size_t *out_size)
{
  // 1. If number is negative or == 0 or == 1, this is not prime number, early return
  //    Time complexity  [1]: O(1)
  //    Space complexity [1]: O(1)
  *out_factors = NULL;
  *out_size = 0ULL;
  //    Time complexity  [2]: O(sqrt num)*O(X), where X - count of times to module divide with
  //                                                      checking and X is parametric, because for
  //                                                      different numbers we'll have different
  //                                                      division times
  //    Space complexity [2]: O(1)
  int number_copy = number; // saving before operator/=
  for (unsigned long factor = 2UL; factor <= sqrt(number); ++factor)
  {
    if (number % factor == 0)
    {
      ++(*out_size);
      while (number % factor == 0)
      {
        number /= factor;
      }
    }
  }
  int remainder = number; // saving remainder after all these divisions
  if (remainder > 1) (*out_size) += 1ULL; // writing down the number itself

  // 3. The same way to iterate over the factors with preallocated necessary space
  //    Time complexity  [3]: O(sqrt num)*O(X)
  //    Space complexity [3]: O(prime factors count)
  number = number_copy;
  size_t idx = 0ULL;
  *out_factors = (unsigned long*)malloc(sizeof(unsigned long) * (*out_size));
  if (out_factors == NULL) return; // malloc failed
  for (unsigned long factor = 2UL; factor <= sqrt(number); ++factor)
  {
    if (number % factor == 0)
    {
      (*out_factors)[idx++] = factor;
      while (number % factor == 0)
      {
        number /= factor;
      }
    }
  }

  // 4. Writing down the number itself as factor
  if (number > 1) (*out_factors)[*out_size - 1ULL] = number;
}

// Time complexity : O(1)+O(n)+O(n)+O(n)*(O(sqrt num)*O(X)+O(h))+O(n*log n)+O(k) = O(n)*(O(sqrt num)*O(X)+O(h))+O(n*log n)+O(k)
// Space complexity: O(1)+O(1)+O(1)*(O(h)*O(Y))+O(1)+O(l) = 3*O(1)+O(1)*(O(h)*O(y))+O(l) = O(h)*O(Y)+O(l)
char *sumOfDivided(const int numbers[/*count*/], int count)
{
  // 1. If there is no elem (we can check only `count` var, because C restricts creation of zero size arrays)
  //    Time complexity  [1]: O(1) -> best case
  //    Space complexity [1]: O(1) -> best case
  if (count == 0) return calloc(1, 1); // NOTE: tests on codewars require to return heap-allocated string!

  // 2. If all the elements are 0 -> there is no factors for null, and null is not a prime number
  //    Time complexity  [2]: O(n)|O(m)|O(1) {worst|midd|best}
  //    Space complexity [2]: O(1)
  if (all_of(numbers, count, is_null)) return calloc(1, 1); // NOTE: tests on codewars require to return heap-allocated string!

  // 3. Iterating over the elements in input array
  //    Time complexity  [3]: O(n)*(O(sqrt num)*O(X)+O(h))
  //    Space complexity [3]: O(1)*(O(h)*O(Y))
  size_t factor_sum_map_size = 0ULL;
  factor_sum_t *factor_sum_map = NULL;

  // Time complexity  [3.1]: O(n)
  // Space complexity [3.1]: O(1)
  for (int number_idx = 0; number_idx < count; ++number_idx)
  {
    unsigned long *factors = NULL;
    size_t factors_size = 0ULL;

    // Time complexity  [3.1.1] -> get_prime_factors: O(sqrt num)*O(X)
    // Space complexity [3.1.1] -> get_prime_factors: O(prime factors count) -> O(h), where h - prime factors count
    get_prime_factors(abs(numbers[number_idx]), &factors, &factors_size);

    // Time complexity  [3.1.2]: O(prime factors count) -> O(h), where h - prime factors count
    // Space complexity [3.1.2]: O(Y), where Y - count of reallocated mem
    for (size_t factor_idx = 0ULL; factor_idx < factors_size; ++factor_idx)
    {
      size_t factor_idx_in_map = find_factor(factor_sum_map, factor_sum_map_size, factors[factor_idx]);
      if (factor_idx_in_map == ULLONG_MAX) // element not found -> need to realloc
      {
        ++factor_sum_map_size;
        factor_sum_map = (factor_sum_t*)realloc(factor_sum_map, sizeof(factor_sum_t) * factor_sum_map_size);
        if (factor_sum_map == NULL) abort(); // realloc failed
        factor_sum_map[factor_sum_map_size - 1ULL].factor = factors[factor_idx];
        factor_sum_map[factor_sum_map_size - 1ULL].sum = numbers[number_idx];
      }
      else // element was find -> just increasing its sum
      {
        factor_sum_map[factor_idx_in_map].sum += numbers[number_idx];
      }
    }

    if (factors) free(factors);
  }

  // 4. Sorting elements of factor_sum mapping by factors
  //    Time complexity  [4]: O(n*log(n))
  //    Space complexity [4]: O(1)
  qsort(factor_sum_map, factor_sum_map_size, sizeof(factor_sum_t), compare_factors);

  // 5. Composing string from mapping
  //    Time complexity  [5]: O(k), where k - length of formatted string
  //    Space complexity [5]: O(l), where l - bytes for resulting string
  char* result = (char *)factor_sum_t_to_string(factor_sum_map, factor_sum_map_size);
  free(factor_sum_map);
  return result;
}

#include <assert.h>

int main(void)
{
  unsigned long *factors = NULL;
  size_t factors_size = 0ULL;

  // --- get_prime_factors tests ---
  get_prime_factors(17, &factors, &factors_size);
  assert(factors[0] == 17);
  assert(factors_size == 1);
  free(factors); factors = NULL;

  get_prime_factors(12, &factors, &factors_size);
  assert(factors[0] == 2);
  assert(factors[1] == 3);
  assert(factors_size == 2);
  free(factors); factors = NULL;

  get_prime_factors(7, &factors, &factors_size);
  assert(factors[0] == 7);
  assert(factors_size == 1);
  free(factors); factors = NULL;

  get_prime_factors(1, &factors, &factors_size);
  assert(factors_size == 0);
  free(factors); factors = NULL;

  get_prime_factors(6, &factors, &factors_size);
  assert(factors[0] == 2);
  assert(factors[1] == 3);
  assert(factors_size == 2);
  free(factors); factors = NULL;

  // --- sumOfDivided tests ---
  char *r = NULL;

  r = sumOfDivided(NULL, 0);
  assert(strcmp(r, "") == 0);
  free(r);

  const int t1[] = {12, 15};
  r = sumOfDivided(t1, 2);
  assert(strcmp(r, "(2 12)(3 27)(5 15)") == 0);
  free(r);

  const int t2[] = {15, 30, -45};
  r = sumOfDivided(t2, 3);
  assert(strcmp(r, "(2 30)(3 0)(5 0)") == 0);
  free(r);

  const int t3[] = {0, 0, 0};
  r = sumOfDivided(t3, 3);
  assert(strcmp(r, "") == 0);
  free(r);

  const int t4[] = {15, 21, 24, 30, 45};
  r = sumOfDivided(t4, 5);
  assert(strcmp(r, "(2 54)(3 135)(5 90)(7 21)") == 0);
  free(r);

  const int t5[] = {107, 158, 204, 100, 118, 123, 126, 110, 116, 100};
  r = sumOfDivided(t5, 10);
  assert(strcmp(r, "(2 1032)(3 453)(5 310)(7 126)(11 110)(17 204)(29 116)(41 123)(59 118)(79 158)(107 107)") == 0);
  free(r);

  const int t6[] = {-29804, -4209, -28265, -72769, -31744};
  r = sumOfDivided(t6, 5);
  assert(strcmp(r, "(2 -61548)(3 -4209)(5 -28265)(23 -4209)(31 -31744)(53 -72769)(61 -4209)(1373 -72769)(5653 -28265)(7451 -29804)") == 0);
  free(r);

  const int t7[] = {17, -17, 51, -51};
  r = sumOfDivided(t7, 4);
  assert(strcmp(r, "(3 0)(17 0)") == 0);
  free(r);

  const int t8[] = {173471};
  r = sumOfDivided(t8, 1);
  assert(strcmp(r, "(41 173471)(4231 173471)") == 0);
  free(r);
}

