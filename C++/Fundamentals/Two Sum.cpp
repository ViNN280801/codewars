#include <iostream>
#include <vector>

/// @brief Searches indexes of the numbers in 'numbers' vector that gives in a sum 'target' number
/// @tparam numbers vector of numbers two search two nums
/// @tparam target target number which will be received by the sum of two numbers from 'numbers' vector
/// @return Indeces of the numbers in 'numbers' vector that gives in a sum 'target' number
template <typename T>
std::pair<std::size_t, std::size_t> two_sum(const std::vector<T> &numbers, T target)
{
    for (size_t i{}; i < numbers.size(); i++)
        for (size_t j{i + 1}; j < numbers.size(); j++)
            if (numbers.at(i) + numbers.at(j) == target)
                return {i, j};
    return {};
}

int main()
{
    std::cout << two_sum({1, 2, 3}, 4).first << '\t' << two_sum({1, 2, 3}, 4).second << std::endl;
    std::cout << two_sum({1234, 5678, 9012}, 14690).first << '\t' << two_sum({1234, 5678, 9012}, 14690).second << std::endl;
    std::cout << two_sum({2, 2, 3}, 4).first << '\t' << two_sum({2, 2, 3}, 4).second << std::endl;

    return EXIT_SUCCESS;
}
