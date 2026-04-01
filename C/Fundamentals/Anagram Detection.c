#include <stdbool.h> // for `bool` type
#include <string.h> // for `strlen` and `memset`
#include <stddef.h> // for `size_t`
#include <ctype.h> // for `tolower`

#define ASCII_COUNT 230 // 256-26 => excluding 26 big letters

bool is_anagram(const char *s1, const char *s2)
{
  // 0. Null strings are not anagram
  if ((s1 == NULL) || (s2 == NULL)) return false;

  size_t s1_size = strlen(s1);
  size_t s2_size = strlen(s2);

  // 1. If sizes are not equal -> this is not anagram
  if (s1_size != s2_size) return false;

  // 2. If `s1 == '\0'` and `s2 == '\0'` (empty strings) make an assumption that this is anagrami
  if (s1_size == 0) return true;

  // 3. If `s1` and `s2` consists of 1 char and this is the same char -> this is anagram
  if ((s1_size == 1) && (tolower(s1[0]) == tolower(s2[0]))) return true;

  // 4. If `s1` and `s2` consists of 1 char, but this 1 char differs
  if ((s1_size == 1) && (s1[0] != s2[0])) return false;

  // 5. Now we need to sure, that:
  //  - all the chars are identically
  //  - count of the same chars are equal
  // We can do it several approaches:
  // 1. sort -> strcmp => Time complexity: O(nlogn) + O(n); Space complexity: O(1)
  // 2. hash table -> compare => Time complexity: O(n); Space complexity: O(n)
  // 3. allocate on stack ascii mapping variable (array) and do ++ for s1 and -- for s2 => Time complexity: O(n)+O(230)=O(n)+O(1)=O(n); Space complexity: O(230) = O(1)
  int ascii_mapping[ASCII_COUNT];
  memset(ascii_mapping, 0, sizeof(ascii_mapping));
  for (size_t i = 0ULL; i < s1_size; ++i)
  {
    ++ascii_mapping[tolower(s1[i])];
    --ascii_mapping[tolower(s2[i])];
  }
  for (unsigned short i = 0; i < ASCII_COUNT; ++i)
  {
    if (ascii_mapping[i] != 0) return false;
  }

  return true;
}

#include <assert.h>

int main(void)
{
  assert(!is_anagram(NULL, NULL));
  assert(is_anagram("", ""));
  assert(is_anagram("z", "z"));
  assert(!is_anagram("g", "n"));
  assert(is_anagram("ana", "ana"));
  assert(!is_anagram("ajuio", "asfnpika"));
  assert(is_anagram("abcde", "edcba"));
  assert(!is_anagram("aab", "abb"));
  assert(is_anagram("Creative", "ReactiVE"));
  assert(is_anagram("t", "T"));

  return 0;
}

