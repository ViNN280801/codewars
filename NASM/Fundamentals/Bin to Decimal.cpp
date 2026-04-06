#include <gtest/gtest.h>

extern "C" {
  unsigned bin_to_dec(char const *);
}

TEST(NASMTests, bin2dec)
{
  EXPECT_EQ(bin_to_dec("0"), 0U);
  EXPECT_EQ(bin_to_dec("1"), 1U);
  EXPECT_EQ(bin_to_dec("10"), 2U);
  EXPECT_EQ(bin_to_dec("11"), 3U);
  EXPECT_EQ(bin_to_dec("1001"), 9U);
  EXPECT_EQ(bin_to_dec("1011"), 11U);
  EXPECT_EQ(bin_to_dec("1010"), 10U);
  EXPECT_EQ(bin_to_dec("1111"), 15U);
  EXPECT_EQ(bin_to_dec("11111111111111111111111111111111"), 4294967295U);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

