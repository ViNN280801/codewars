// Task: Given an array of integers, return a
// new array with each value doubled.

// For example:
// [1, 2, 3] --> [2, 4, 6]

#include <iostream>
#include <vector>
#include <ranges> // since C++20
#include <span>   // since C++20

// Since C++20
// Returns array where all elements are doubled
template <typename numeric_t>
std::vector<numeric_t> maps(std::span<const numeric_t> __range)
{
    std::vector<numeric_t> result_range;

    for (const auto &el : __range)
    {
        result_range.push_back(el * 2.0);
    }

    return result_range;
}

// Returns array where all elements are doubled
template <typename numeric_t>
std::vector<numeric_t> maps(const std::vector<numeric_t> &__range)
{
    std::vector<numeric_t> result_vec;

    for (const auto &el : __range)
    {
        result_vec.push_back(el * 2.0);
    }

    return result_vec;
}

// Prints range to terminal by iterators
template <typename Iter>
void print_range(Iter begin, Iter end)
{
    for (auto iter{begin}; iter != end; ++iter)
    {
        std::cout << *iter << ' ';
    }
    endl(std::cout);
}

int main()
{
    std::vector vec{1, 2, 3};
    print_range(std::cbegin(vec), std::cend(vec));

    vec = maps<int>(vec);
    print_range(std::cbegin(vec), std::cend(vec));

    return EXIT_SUCCESS;
}
