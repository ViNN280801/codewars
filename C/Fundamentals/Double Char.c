#include <complex.h>
#include <string.h> // for `strlen `
#include <stddef.h> // for `size_t`

char *double_char (const char *string, char *doubled)
{
  if ((string == NULL) || (doubled == NULL)) return "";
  size_t doubled_size = strlen(string) * 2ULL;
  doubled[doubled_size] = '\0';

  size_t i = 0ULL;
  while (i < doubled_size)
  {
    doubled[i] = string[i / 2ULL];
    doubled[i + 1ULL] = string[i / 2ULL];
    i += 2ULL;
  }

  return doubled;
}

#include <assert.h>
#include <stdlib.h>

int main(void)
{
  char *doubled = (char*)malloc(100);
  assert(strcmp(double_char("", doubled), "") == 0);
  assert(strcmp(double_char("a", doubled), "aa") == 0);
  assert(strcmp(double_char("ab", doubled), "aabb") == 0);
  assert(strcmp(double_char("abc_", doubled), "aabbcc__") == 0);
  assert(strcmp(double_char("@#gt", doubled), "@@##ggtt") == 0);
  assert(strcmp(double_char("AJGag", doubled), "AAJJGGaagg") == 0);
  assert(strcmp(double_char("test", doubled), "tteesstt") == 0);
  assert(strcmp(double_char("Hello, W0rLd!", doubled), "HHeelllloo,,  WW00rrLLdd!!") == 0);
  assert(strcmp(double_char("a b c", doubled), "aa  bb  cc") == 0);
  assert(strcmp(double_char("a_ tz", doubled), "aa__  ttzz") == 0);
  assert(strcmp(double_char("D0 Vbl  3D   ", doubled), "DD00  VVbbll    33DD      ") == 0);

  free(doubled);
  return 0;
}

