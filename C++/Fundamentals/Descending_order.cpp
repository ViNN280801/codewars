// Task: Your task is to make a function that can take any non-negative
// integer as an argument and return it with its digits in descending order.
// Essentially, rearrange the digits to create the highest possible number.

// Examples:
// Input: 42145 Output: 54421
// Input: 145263 Output: 654321
// Input: 123456789 Output: 987654321

#include <cinttypes>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

// Returns 'T' as string
template <typename T>
std::string my_to_string(const T &__value)
{
    std::ostringstream oss;
    oss << __value;
    return oss.str();
}

// Returns string parameter as T
template <typename T>
T string_to_T(const std::string &__str)
{
    T value;
    std::istringstream iss(__str);
    iss >> value;
    return value;
}

// Returns '__num' in sorted view and in descending order
uint64_t descendingOrder(const uint64_t &__num)
{
    std::string num_in_str{my_to_string(__num)};
    std::sort(std::begin(num_in_str), std::end(num_in_str));
    std::reverse(std::begin(num_in_str), std::end(num_in_str));
    return string_to_T<uint64_t>(num_in_str);
}

int main()
{
    uint64_t value{descendingOrder(0UL)};
    std::cout << value << std::endl;

    value = descendingOrder(1UL);
    std::cout << value << std::endl;

    value = descendingOrder(15UL);
    std::cout << value << std::endl;

    value = descendingOrder(1021UL);
    std::cout << value << std::endl;

    value = descendingOrder(123456789UL);
    std::cout << value << std::endl;

    return EXIT_SUCCESS;
}
