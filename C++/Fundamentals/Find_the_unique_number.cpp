// Task: There is an array with some numbers. All numbers are equal except for one. Try to find it!

// find_uniq(std::vector<float>{1, 1, 1, 2, 1, 1});  // --> 2
// find_uniq(std::vector<float>{0, 0, 0.55, 0, 0});  // --> 0.55

// It’s guaranteed that array contains at least 3 numbers.
// The tests contain some very huge arrays, so think about performance.

// This is the first kata in series:
// Find the unique number (this kata)
// Find the unique string (https://www.codewars.com/kata/585d8c8a28bc7403ea0000c3)
// Find The Unique (https://www.codewars.com/kata/5862e0db4f7ab47bed0000e5)

#include <iostream>
#include <string>
#include <vector>
#include <span> // Since C++20

template <typename T>
void print_range(const std::vector<T> &__range)
{
    for (const auto &el : __range)
    {
        std::cout << el << ' ';
    }
    endl(std::cout);
}

// Fills vector with elements from span
template <typename T>
void fill_vec_with_span_elems(std::span<const T> __src, std::vector<T> &__dest)
{
    for (const auto &el : __src)
    {
        __dest.push_back(el);
    }
}

// Since C++20
// Returns unique value from the range
template <typename T>
T find_uniq(std::span<const T> __range)
{
    std::vector<T> vec;
    T non_unique_val{};
    fill_vec_with_span_elems(__range, vec);

    for (auto it{std::cbegin(vec)}; it != std::cend(vec); ++it)
    {
        if ((*it) == (*(it + 1)))
        {
            non_unique_val = *it;
            break;
        }
    }

    for (auto it{std::cbegin(vec)}; it != std::cend(vec); ++it)
    {
        if (*it != non_unique_val)
            return *it; // This is the unique value
    }

    return T();
}

// Returns unique value from the range
template <typename T>
T find_uniq(const std::vector<T> &__vec)
{
    T non_unique_val{};

    for (auto it{std::cbegin(__vec)}; it != std::cend(__vec); ++it)
    {
        if ((*it) == (*(it + 1)))
        {
            non_unique_val = *it;
            break;
        }
    }

    for (auto it{std::cbegin(__vec)}; it != std::cend(__vec); ++it)
    {
        if (*it != non_unique_val)
            return *it; // This is the unique value
    }

    return T();
}

// Codewars version to test
// Returns unique value from the range
float find_uniq(const std::vector<float> &__vec)
{
    float non_unique_val{};

    for (auto it{std::cbegin(__vec)}; it != std::cend(__vec); ++it)
    {
        if ((*it) == (*(it + 1)))
        {
            non_unique_val = *it;
            break;
        }
    }

    for (auto it{std::cbegin(__vec)}; it != std::cend(__vec); ++it)
    {
        if (*it != non_unique_val)
            return *it; // This is the unique value
    }

    return 0.0F;
}

int main()
{
    std::cout << find_uniq<float>(std::vector<float>{1, 1, 1, 2, 1, 1}) << std::endl;
    std::cout << find_uniq<float>(std::vector<float>{0, 0, 0.55, 0, 0}) << std::endl;
    std::cout << find_uniq<float>(std::vector<float>{999.666, 999.666, 999.666, 999.666, 999.666, 999.666, 999.666, 999, 999.666}) << std::endl;

    return EXIT_SUCCESS;
}
