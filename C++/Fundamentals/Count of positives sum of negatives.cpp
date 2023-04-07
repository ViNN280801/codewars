#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

std::vector<int>
countPositivesSumNegatives(std::vector<int> input)
{
    if (input.empty())
        return std::vector<int>({});

    return std::vector<int>({static_cast<int>(std::count_if(std::cbegin(input), std::cend(input), [](int const &el)
                                                            { return el > 0; })),
                             std::accumulate(std::cbegin(input), std::cend(input), 0, [](int const &res, int const &val)
                                             { return (val < 0) ? res + val : res; })});
}

int main()
{
    std::vector<int> v{countPositivesSumNegatives(std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15}))};
    std::cout << *std::cbegin(v) << '\t' << *(std::cend(v) - 1) << std::endl;

    return EXIT_SUCCESS;
}
