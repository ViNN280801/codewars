// Task: Complete the function that takes two integers (a, b, where a < b) and
// return an array of all integers between the input parameters, including them.

// For example:
// a = 1
// b = 4
// --> [1, 2, 3, 4]

#include <iostream>
#include <vector>

template <typename T = int>
constexpr void printRange(const std::vector<T> &range)
{
    for (auto elem : range)
    {
        std::cout << elem << ' ';
    }
    std::endl(std::cout);
}

// Returns a vector with elements from 'start' to 'end'
template <typename T = int>
constexpr std::vector<T> between(int start, int end)
{
    if (start > end)
        return {0};

    std::vector<T> res;
    int i{start};
    while (i <= end)
    {
        res.push_back(i);
        i++;
    }
    return res;
}

#include <numeric>
#include <iterator>
// Returns a vector with elements from 'start' to 'end'
template <typename T = int>
constexpr std::vector<T> betweenSmart(int start, int end)
{
    std::vector<T> res(end - start + 1);
    std::iota(std::begin(res), std::end(res), start);
    return res;
}

int main()
{
    printRange(between(5, 5));
    printRange(between(1, 4));

    std::cout << "\nWith iota(): " << std::endl;

    printRange(betweenSmart(5, 5));
    printRange(betweenSmart(1, 4));

    return EXIT_SUCCESS;
}
