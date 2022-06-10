// Task: In this simple assignment you are given a number and have to make it negative. But maybe the number is already negative?

#include <iostream>
#include <cmath>

// Making number negative
int makeNegativeClever(int num)
{
    return -abs(num);
}

// Making number negative
int makeNegative(int num)
{
    return (num < 0) ? num : (-num);
}

int main(int argc, char *argv[])
{
    // Showing result of making negative number
    std::cout << makeNegative(2) << std::endl;
    std::cout << makeNegative(-5) << std::endl;

    // Showing result of making negative number with clever function
    std::cout << makeNegativeClever(9) << std::endl;
    std::cout << makeNegativeClever(-1) << std::endl;

    return EXIT_SUCCESS;
}