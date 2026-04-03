#include <algorithm>
#include <string>
#include <string_view>

std::string double_char(std::string_view str)
{
  std::string result;
  result.reserve(str.length() * 2ULL);
  std::for_each(str.cbegin(), str.cend(), [&result](char const ch){
    result += ch;
    result += ch;
  });
  return result;

  // Time complexity: O(n), where n = str.length()
  // Space complexity: O(2*n) = O(n)
}

#include <cassert>

int main()
{
  assert(double_char("") == "");
  assert(double_char("a") == "aa");
  assert(double_char("ab") == "aabb");
  assert(double_char("abc_") == "aabbcc__");
  assert(double_char("@#gt") == "@@##ggtt");
  assert(double_char("AJGag") == "AAJJGGaagg");
  assert(double_char("test") == "tteesstt");
  assert(double_char("Hello, W0rLd!") == "HHeelllloo,,  WW00rrLLdd!!");
  assert(double_char("a b c") == "aa  bb  cc");
  assert(double_char("a_ tz") == "aa__  ttzz");
  assert(double_char("D0 Vbl  3D   ") == "DD00  VVbbll    33DD      ");

  return EXIT_SUCCESS;
}

