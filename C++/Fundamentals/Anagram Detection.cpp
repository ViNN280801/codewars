#include <algorithm>
#include <string_view>
#include <cctype>
#include <unordered_map>

bool isAnagram(std::string_view test, std::string_view original)
{
  if (test.empty() && original.empty()) return true;
  if (test.length() != original.length()) return false;
  if (test.length() == 1 && original.length() == 1)
  {
    if (std::tolower(test.front()) == std::tolower(original.front())) return true;
    else return false;
  }
  std::unordered_map<int, int> char_mapping;
  for (std::size_t i{}; i < test.length(); ++i)
  {
    ++char_mapping[std::tolower(test.at(i))];
    --char_mapping[std::tolower(original.at(i))];
  }
  return !std::any_of(char_mapping.cbegin(), char_mapping.cend(), [](auto const &symbol_counter){ return symbol_counter.second != 0; });
}

#include <cassert>

int main(void)
{
  assert(isAnagram("", ""));
  assert(isAnagram("z", "z"));
  assert(!isAnagram("g", "n"));
  assert(isAnagram("ana", "ana"));
  assert(!isAnagram("ajuio", "asfnpika"));
  assert(isAnagram("abcde", "edcba"));
  assert(!isAnagram("aab", "abb"));
  assert(isAnagram("Creative", "ReactiVE"));
  assert(isAnagram("t", "T"));

  return 0;
}

