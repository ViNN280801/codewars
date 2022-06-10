// Task: Complete the square sum function so that it squares each number passed into it and then sums the results together.
// For example, for [1, 2, 2] it should return 9 because 1^2 + 2^2 + 2^2 = 9.

#include <iostream>
#include <vector>

// Square sum function so that it squares each number passed into it and then sums the results together
int square_sum(const std::vector<int> &numbers)
{
    int result{};

    for (size_t iter = 0; iter < numbers.size(); iter++)
    {
        result += numbers[iter] * numbers[iter];
    }

    return result;
}

int main(int argc, char *argv[])
{
    // Initializing vector of integers
    std::vector<int> vecInt{1, 2, 2};

    // Showing result of work function 'square_sum'
    std::cout << square_sum(vecInt) << std::endl;

    vecInt.push_back(5);
    std::cout << square_sum(vecInt) << std::endl;
    vecInt.push_back(3);
    std::cout << square_sum(vecInt) << std::endl;

    return EXIT_SUCCESS;
}