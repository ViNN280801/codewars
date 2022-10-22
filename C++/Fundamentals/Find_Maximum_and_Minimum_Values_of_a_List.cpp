// Task: Your task is to make two functions
// (max and min, or maximum and minimum, etc., depending on the language)
// that receive a list of integers as input, and return the largest and
// lowest number in that list, respectively.

// Examples (Input -> Output):
// * [4,6,2,1,9,63,-134,566]         -> max = 566, min = -134
// * [-52, 56, 30, 29, -54, 0, -110] -> min = -110, max = 56
// * [42, 54, 65, 87, 0]             -> min = 0, max = 87
// * [5]                             -> min = 5, max = 5

// Notes
// You may consider that there will not be any empty arrays/vectors.

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

template <typename T>
T min(const std::vector<T> &__list)
{
    std::vector<T> list{__list};
    std::sort(std::begin(list), std::end(list));
    return *(std::cbegin(list));
}

template <typename T>
T max(const std::vector<T> &__list)
{
    std::vector<T> list{__list};
    std::sort(std::rbegin(list), std::rend(list));
    return *(std::cbegin(list));
}

int main()
{
    std::cout << min<int>({-52, 56, 30, 29, -54, 0, -110}) << std::endl;
    std::cout << min<int>({42, 54, 65, 87, 0}) << std::endl;
    std::cout << max<int>({4, 6, 2, 1, 9, 63, -134, 566}) << std::endl;
    std::cout << max<int>({5}) << std::endl;

    return EXIT_SUCCESS;
}
