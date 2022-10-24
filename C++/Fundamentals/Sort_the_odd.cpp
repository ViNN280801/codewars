// Task: You will be given an array of numbers. You have to sort the odd numbers
// in ascending order while leaving the even numbers at their original positions.

// Examples:
// [7, 1]  =>  [1, 7]
// [5, 8, 6, 3, 4]  =>  [3, 8, 6, 5, 4]
// [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]  =>  [1, 8, 3, 6, 5, 4, 7, 2, 9, 0]

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <span>

// Since C++20 (need std::span)
// Prints range to terminal
template <typename T>
void print_range(std::span<const T> __range)
{
    for (const auto &el : __range)
    {
        std::cout << el << ' ';
    }
    endl(std::cout);
}

// Prints vector of pairs to terminal
template <typename T1, typename T2>
void print_pair_vec(const std::vector<std::pair<T1, T2>> &__vec)
{
    for (size_t index{0UL}; index < __vec.size(); index++)
    {
        std::cout << "array[" << __vec.at(index).first << "] = " << __vec.at(index).second << std::endl;
    }
}

// Returns vector of pairs from two vectors same length
template <typename T1, typename T2>
std::vector<std::pair<T1, T2>> make_vector_of_pairs_by_two_vectors(const std::vector<T1> &__vec1, const std::vector<T2> &__vec2)
{
    std::vector<std::pair<T1, T2>> result_vec;
    std::vector<T1> vec1(__vec1);
    std::vector<T2> vec2(__vec2);

    result_vec.reserve(__vec1.size());
    std::transform(std::begin(vec1), std::end(vec1), std::begin(vec2), std::back_inserter(result_vec),
                   [](auto value1, auto value2)
                   {
                       return std::make_pair(value1, value2);
                   });

    return result_vec;
}

class Kata
{
protected:
    template <typename T1, typename T2>
    static std::vector<std::pair<T1, T2>> get_vector_of_indeces_and_odds_with_sorted_values(const std::vector<int> &__array)
    {
        std::vector<size_t> indeces;
        std::vector<int> odds;

        for (size_t index{0UL}; index < __array.size(); index++)
        {
            if (__array.at(index) % 2 != 0)
            {
                indeces.push_back(index);
                odds.push_back(__array.at(index));
            }
        }

        std::sort(std::begin(odds), std::end(odds));

        // Defining a vector of a pair which consist of index of odds numbers
        // and odds itself
        return make_vector_of_pairs_by_two_vectors(indeces, odds);
    }

public:
    std::vector<int> sortArray(std::vector<int> array)
    {
        std::vector<std::pair<size_t, int>>
            indeces_and_odds{get_vector_of_indeces_and_odds_with_sorted_values<size_t, int>(array)};

        for (size_t index{0UL}; index < array.size(); index++)
        {
            for (size_t pair_index{0UL}; pair_index < indeces_and_odds.size(); pair_index++)
            {
                if (index == indeces_and_odds.at(pair_index).first)
                    array.at(index) = indeces_and_odds.at(pair_index).second;
            }
        }

        return array;
    }

    std::vector<int> clever_sortArray(std::vector<int> array)
    {
        std::vector<int> odds;
        std::copy_if(array.begin(), array.end(), std::back_inserter(odds), [](int x)
                     { return x % 2; });
        std::sort(odds.begin(), odds.end());
        for (int i = 0, j = 0; i < array.size(); i++)
            if (array[i] % 2)
                array[i] = odds[j++];
        return array;
    }
};

int main()
{
    Kata kata;
    print_range<int>(kata.sortArray(std::vector<int>{5, 3, 2, 8, 1, 4}));

    return EXIT_SUCCESS;
}
