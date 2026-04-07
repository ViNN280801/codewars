#include <cstring> // for `strcmp`

#include <gtest/gtest.h>

extern "C" {
  const char* how_much_i_love_you(int nb_petals);
}

char const *how_much_i_love_you_c_impl(int nb_petals) {
  char const *phrases[] = {
    "I love you",
    "a little",
    "a lot",
    "passionately",
    "madly",
    "not at all"
  };
  return phrases[(nb_petals - 1) % 6];
}

TEST(NASMTests, howMuchILoveYou)
{
  for (int i = 1; i <= 100'000; ++i)
    EXPECT_TRUE(strcmp(how_much_i_love_you(i), how_much_i_love_you_c_impl(i)) == 0);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

