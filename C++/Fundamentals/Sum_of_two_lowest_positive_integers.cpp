// Create a function that returns the sum of the two lowest positive numbers
// given an array of minimum 4 positive integers. No floats or non-positive integers will be passed.

// For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

// [10, 343445353, 3453445, 3453545353453] should return 3453455.

#include <iostream>
#include <vector>
#include <algorithm>

long sumTwoSmallestNumbers(std::vector<int> __numbers)
{
    std::sort(std::begin(__numbers), std::end(__numbers));
    long sum{0UL};
    ushort index{0U};

    for (const auto &num : __numbers)
    {
        if (index <= 1UL)
        {
            sum += num;
            index++;
        }
    }

    return sum;
}

int main()
{
    std::vector vec{5, 8, 12, 19, 22};
    std::cout << sumTwoSmallestNumbers(vec) << std::endl;

    return EXIT_SUCCESS;
}
