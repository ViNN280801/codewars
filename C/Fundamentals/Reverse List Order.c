#include <stdlib.h> // for mem management
#include <stddef.h> // for `size_t` type

#define HEAP_ALLOC(type, count) ((type*)calloc((count), sizeof(type)))

// Time complexity :
//   - best  case: O(1) - early return or 0|1 elements
//   - worst case: O(1)+O(1)+O(n) = 2*O(1)+O(n) = O(n)
// Space complexity:
//   - best  case: O(1) - early return or 0|1 elements
//   - worst case: O(1)+O(n)+O(1) = 2*O(1)+O(n) = O(n)
int *reverse_list(int const *arr, size_t arr_size)
{
  // 1. If smth wrong in ptr or size, early return
  //    Time complexity  [1]: O(1) -> best case opt1
  //    Space complexity [1]: O(1) -> best case opt1
  if (arr == NULL || arr_size == 0ULL) return HEAP_ALLOC(int, 1ULL);

  // 2. Allocating mem with check
  //    Time complexity  [2]: O(1) -> best case opt2
  //    Space complexity [2]: O(n), where n - count of elements in input array -> best case opt2 O(1), if calloc failed
  int *reversed = HEAP_ALLOC(int, arr_size);
  if (reversed == NULL) return HEAP_ALLOC(int, 1ULL);

  // 3. Iteration from end to begin
  //   Time complexity  [3]: O(n)
  //   SPace complexity [3]: O(1) - algorithm always allocated 2*sizeof(size_t), which is impl defined
  size_t i = 0ULL;
  while (i != arr_size) { reversed[arr_size - 1ULL - i] = arr[i]; ++i; }
  return reversed;
}

#include <assert.h>

#ifdef DEBUG
  #include <stdio.h>
#endif

void do_test(size_t arr_size, int const arr[], int const expected[])
{
  static short test_idx = 1;

  int *reversed = reverse_list(arr, arr_size);
  assert(reversed != NULL);
#ifdef DEBUG
  printf("===== TEST [%d] =====\n", test_idx);
  for (size_t i = 0ULL; i < arr_size; ++i) printf("%d ", reversed[i]);
  printf("\n");
  for (size_t i = 0ULL; i < arr_size; ++i) printf("%d ", expected[i]);
  printf("\n\n");
#endif
  for (size_t i = 0ULL; i < arr_size; ++i) assert(reversed[i] == expected[i]);
  free(reversed);
  ++test_idx;
}

int main(void)
{
  int arr1[] = {1};
  int expected1[] = {1};
  do_test(1, arr1,  expected1);

  int const arr2[] = {1, 2};
  int const expected2[] = {2, 1};
  do_test(2, arr2, expected2);

  int const arr3[] = {1, 2, 3, 6, 7, 8, 10, 32, -1, -5};
  int const expected3[] = {-5, -1, 32, 10, 8, 7, 6, 3, 2, 1};
  do_test(10, arr3, expected3);

  int const arr4[] = {4, -15, 17, -8, 12, 0, 0, 1, 0};
  int const expected4[] = {0, 1, 0, 0, 12, -8, 17, -15, 4};
  do_test(9, arr4, expected4);

  return 0;
}

