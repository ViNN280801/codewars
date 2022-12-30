// Complete the function that takes a non-negative integer n as input,
// and returns a list of all the powers of 2
// with the exponent ranging from 0 to n (inclusive).

#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
#include <span>

template <typename T>
constexpr void printVec(std::span<const T> range)
{
    for (const auto &el : range)
    {
        std::cout << el << ' ';
    }
    endl(std::cout);
}

// Returns 'n' degrees of number 2
std::vector<uint64_t> powers_of_two(int n)
{
    std::vector<uint64_t> vec;
    for (int i{0}; i <= n; i++)
        vec.push_back(pow(2, i));
    return vec;
}

int main()
{
    std::vector<uint64_t> vec(powers_of_two(0));
    printVec<uint64_t>(vec);

    return EXIT_SUCCESS;
}
