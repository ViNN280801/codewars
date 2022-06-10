// Task: Write a program that will calculate the number of trailing zeros in a factorial of a given number.
// N! = 1 * 2 * 3 * ... * N
// Be careful 1000! has 2568 digits...
// For more info, see: http://mathworld.wolfram.com/Factorial.html

#include <iostream>
#include <cmath>

// Calculating the number of trailing zeros in a factorial of a given number
long zeros(long n)
{
    const int k_max{static_cast<int>(log2(n) / log2(5))};
    long zeroCounter{};

    for (int iter = 1; iter <= k_max; iter++)
    {
        zeroCounter += n / pow(5, iter);
    }

    return zeroCounter;
}

int main(int argc, char *argv[])
{
    // Showing result of work function 'zeros'
    std::cout << zeros(128497340) << std::endl;
    std::cout << zeros(32) << std::endl;

    return EXIT_SUCCESS;
}