// Task: Given an array of integers your solution should find the smallest integer.

// For example:
// Given [34, 15, 88, 2] your solution will return 2
// Given [34, -345, -1, 100] your solution will return -345

// You can assume, for the purpose of this kata, that the supplied array will not be empty.

#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <iterator>

template <typename T = int>
constexpr int findSmallest(const std::vector<T> &list)
{
    if (list.empty())
        return 0;

    if constexpr (std::is_convertible_v<T, int>)
        return *std::min_element(std::cbegin(list), std::cend(list));
}

int main()
{
    std::cout << findSmallest(std::vector<int>{0}) << std::endl;
    std::cout << findSmallest(std::vector<int>{3, 5, 2}) << std::endl;
    std::cout << findSmallest(std::vector<int>{7, 4, 6, 8}) << std::endl;
    std::cout << findSmallest(std::vector<int>{17, 21, 15, 36, 96}) << std::endl;
    std::cout << findSmallest(std::vector<int>{3, 9, 13, 10, 5, 3, 9, 5}) << std::endl;
    std::cout << findSmallest(std::vector<int>{-12, -52, -27}) << std::endl;
    std::cout << findSmallest(std::vector<int>{-3, -27, -4, -2, -27, -2}) << std::endl;
    std::cout << findSmallest(std::vector<int>{-16, -37, -8, -46, -29}) << std::endl;
    std::cout << findSmallest(std::vector<int>{-14, -102, -96, -36, -46, -15, -44}) << std::endl;
    std::cout << findSmallest(std::vector<int>{12, 0, -27}) << std::endl;
    std::cout << findSmallest(std::vector<int>{-13, -50, 57, 13, 67, -13, 57, 108, 67}) << std::endl;
    std::cout << findSmallest(std::vector<int>{-23, 12, 0, -47, -3, 24}) << std::endl;
    std::cout << findSmallest(std::vector<int>{34, -345, -1, 100}) << std::endl;
    std::cout << findSmallest(std::vector<int>{34, 15, 88, 2}) << std::endl;
    std::cout << findSmallest(std::vector<int>{}) << std::endl;

    return EXIT_SUCCESS;
}
