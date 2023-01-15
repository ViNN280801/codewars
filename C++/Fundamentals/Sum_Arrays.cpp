// Task: Write a function that takes an array of numbers and
// returns the sum of the numbers. The numbers can be negative or non-integer.
// If the array does not contain any numbers then you should return 0.

// Examples:

// Input: [1, 5.2, 4, 0, -1]
// Output: 9.2

// Input: []
// Output: 0

// Input: [-2.398]
// Output: -2.398

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

// Returns sum of elements in 'nums' array
int sum(const std::vector<int> &__nums)
{
    return std::accumulate(std::cbegin(__nums), std::cend(__nums), 0);
}

int main()
{
    std::cout << sum(std::vector<int>{}) << std::endl;
    std::cout << sum(std::vector<int>{5}) << std::endl;
    std::cout << sum(std::vector<int>{-5}) << std::endl;
    std::cout << sum(std::vector<int>{1, 2, 3, 4}) << std::endl;
    std::cout << sum(std::vector<int>{1, 2, -3, 3, 4}) << std::endl;

    return EXIT_SUCCESS;
}