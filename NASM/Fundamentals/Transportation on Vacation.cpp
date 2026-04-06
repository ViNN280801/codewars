#include <gtest/gtest.h>

extern "C" {
  unsigned rental_car_cost(unsigned);
}

TEST(NASMTests, rentalCarCost)
{
  EXPECT_EQ(rental_car_cost(0), 0);
  EXPECT_EQ(rental_car_cost(1), 40);
  EXPECT_EQ(rental_car_cost(2), 80);
  EXPECT_EQ(rental_car_cost(3), 100);
  EXPECT_EQ(rental_car_cost(4), 140);
  EXPECT_EQ(rental_car_cost(5), 180);
  EXPECT_EQ(rental_car_cost(6), 220);
  EXPECT_EQ(rental_car_cost(7), 230);
  EXPECT_EQ(rental_car_cost(8), 270);
  EXPECT_EQ(rental_car_cost(9), 310);
  EXPECT_EQ(rental_car_cost(10), 350);
  EXPECT_EQ(rental_car_cost(150), 5950);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

