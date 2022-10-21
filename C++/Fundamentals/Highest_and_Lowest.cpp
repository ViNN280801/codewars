// Task: In this little assignment you are given a string of space separated numbers,
// and have to return the highest and lowest number.

// Examples:
// highAndLow("1 2 3 4 5");  // return "5 1"
// highAndLow("1 2 -3 4 5"); // return "5 -3"
// highAndLow("1 9 3 4 -5"); // return "9 -5"

// Notes
// All numbers are valid Int32, no need to validate them.
// There will always be at least one number in the input string.
// Output string must be two numbers separated by a single space, and highest number is first.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

// Returns vector of numbers with 'int32_t' type from a string
std::vector<int32_t> str_to_numbers_vec(const std::string &__str)
{
    std::stringstream ss(__str);
    std::vector<int32_t> nums_vec;
    int32_t number{0};

    while (ss >> number)
    {
        nums_vec.push_back(number);
    }

    return nums_vec;
}

// Return highest and lowest number from a string represented as an array of a numbers
std::string highAndLow(const std::string &__numbers)
{
    std::vector<int32_t> nums_vec{str_to_numbers_vec(__numbers)};
    std::sort(std::begin(nums_vec), std::end(nums_vec));
    std::string hi_lo{std::to_string((*std::rbegin(nums_vec))) + " " + std::to_string((*std::begin(nums_vec)))};

    return hi_lo;
}

int main()
{
    std::cout << highAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4") << std::endl;
    std::cout << highAndLow("1 2 3") << std::endl;

    return EXIT_SUCCESS;
}
