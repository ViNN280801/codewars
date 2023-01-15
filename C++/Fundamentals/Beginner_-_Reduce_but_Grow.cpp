// Task: Given a non-empty array of integers, return
// the result of multiplying the values together in order. Example:

// [1, 2, 3, 4] => 1 * 2 * 3 * 4 = 24

#include <iostream>
#include <vector>
#include <span> // from C++20

// Returns result of mathematical operation 'op' that applies to each element of range
template <typename Iter, typename StartValue, typename Operation>
auto accumulateData(Iter begin, Iter end, StartValue start_value, Operation op)
{
    auto accumulated{start_value};
    for (Iter iter{begin}; iter != end; ++iter)
    {
        accumulated = op(accumulated, *iter);
    }
    return accumulated;
}

// Returns product of each element in range
int grow(std::span<const int> __range)
{
    return accumulateData(std::cbegin(__range), std::cend(__range), 1, std::multiplies<>{});
}

// Returns product of each element in range
int grow(const std::vector<int> &__range)
{
    return accumulateData(std::cbegin(__range), std::cend(__range), 1, std::multiplies<>{});
}

int main()
{
    std::vector vec{1, 2, 3};
    std::cout << grow(vec) << std::endl;
    
    vec = {4, 1, 1, 1, 4};
    std::cout << grow(vec) << std::endl;

    vec = {2, 2, 2, 2, 2, 2};
    std::cout << grow(vec) << std::endl;

    return EXIT_SUCCESS;
}
