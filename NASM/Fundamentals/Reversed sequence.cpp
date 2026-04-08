#include <limits> // for max of `unsigned short` type

#include <stdlib.h> // for mem management
#include <string.h> // for `strcmp` for testing
#include <stddef.h> // for `size_t` type

#include <gtest/gtest.h>

#define HEAP_ALLOC(type, count) ((type*)calloc((count), sizeof(type)))

/* ===== NASM Impl ===== */
extern "C" {
  int *reverse_seq(int, size_t *);
}

/* ===== C Impl ===== */
int *reverse_seq_checker(int num, size_t *out_size)
{
  if (num == 0U || out_size == NULL) return NULL;
  int *result = HEAP_ALLOC(int, num);
  if (result == NULL) return NULL;
  int num_copy = num;
  *out_size = num;
  for (int i = 0; i < num_copy; ++i) result[i] = num--;
  return result;
}

TEST(NASMTests, reverseSequence)
{
  for (int i{}; i < std::numeric_limits<int>::max(); ++i)
  {
    size_t test_size = 0ULL;
    int *test        = reverse_seq(i, &test_size);

    size_t expected_size = 0ULL;
    int *expected        = reverse_seq_checker(i, &expected_size);

    EXPECT_EQ(test_size, expected_size);
    for (int j{}; j < i; ++j)
    {
      EXPECT_EQ(test[j], expected[j]);
    }

    free(test);
    free(expected);
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

