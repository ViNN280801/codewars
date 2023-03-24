#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

// Returns "true" if 'num' is <= 0, otherwise - "false"
constexpr bool isLessOrEqTo0(int const &num)
{
    return num <= 0;
}

// Returns sum of every number from 1 to 'num'
int summation(int const &num)
{
    if (isLessOrEqTo0(num))
        return 0;

    // Initialize vector that contains 'num' elements
    std::vector<int> vec(num);
    std::iota(std::begin(vec), std::end(vec), num - (num - 1));
    return std::accumulate(std::cbegin(vec), std::cend(vec), 0);
}

// Returns sum of every number from 1 to 'num'
int summation_v2(int num)
{
    if (isLessOrEqTo0(num))
        return 0;

    int sum{};
    while (num > 0)
    {
        sum += num;
        num--;
    }
    return sum;
}

// Returns sum of every number from 1 to 'num'
int summation_v3(int num)
{
    if (isLessOrEqTo0(num))
        return 0;

    if (num == 1)
        return 1;
    else
        return num + summation_v3(num - 1);
}

// Returns sum of every number from 1 to 'num'
constexpr int summation_clever(int num)
{
    // For example, 5: 5 * 6 / 2 = 15
    // 1: 1 * 2 / 2 = 1
    // 8: 8 * 9 / 2 = 36
    return num * (num + 1) / 2;
}

int main()
{
    std::cout << summation(1) << std::endl;
    std::cout << summation(5) << std::endl;
    std::cout << summation(8) << std::endl;

    std::cout << "\nSummation_v2" << std::endl;
    std::cout << summation_v2(1) << std::endl;
    std::cout << summation_v2(5) << std::endl;
    std::cout << summation_v2(8) << std::endl;

    std::cout << "\nSummation_v3" << std::endl;
    std::cout << summation_v3(1) << std::endl;
    std::cout << summation_v3(5) << std::endl;
    std::cout << summation_v3(8) << std::endl;

    std::cout << "\nSummation_clever" << std::endl;
    std::cout << summation_clever(1) << std::endl;
    std::cout << summation_clever(5) << std::endl;
    std::cout << summation_clever(8) << std::endl;

    return EXIT_SUCCESS;
}
