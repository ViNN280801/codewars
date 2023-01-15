// Task: Given an array of integers, find the one that appears an odd number of times.

// There will always be only one integer that appears an odd number of times.
// Examples

// [7] should return 7, because it occurs 1 time (which is odd).
// [0] should return 0, because it occurs 1 time (which is odd).
// [1,1,2] should return 2, because it occurs 1 time (which is odd).
// [0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
// [1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int findOdd(const std::vector<int> &__numbers)
{
    std::vector numbers(__numbers);
    int num{0};

    for (auto it{std::cbegin(numbers)}; it != std::cend(numbers); ++it)
    {
        auto repeats(std::count(std::begin(numbers), std::end(numbers), *it));
        if (repeats % 2 != 0)
            num = *it;
    }

    return num;
}

int main()
{
    std::cout << findOdd(std::vector<int>{20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5}) << std::endl;
    std::cout << findOdd(std::vector<int>{1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5}) << std::endl;
    std::cout << findOdd(std::vector<int>{20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5}) << std::endl;
    std::cout << findOdd(std::vector<int>{10}) << std::endl;
    std::cout << findOdd(std::vector<int>{1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1}) << std::endl;

    return EXIT_SUCCESS;
}
