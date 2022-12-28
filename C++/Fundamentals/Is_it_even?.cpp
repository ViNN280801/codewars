// Task: In this Kata we are passing a number (n) into a function.
// Your code will determine if the number passed is even (or not).
// The function needs to return either a true or false.
// Numbers may be positive or negative, integers or floats.
// Floats with decimal part non equal to zero are considered UNeven for this kata.

#include <iostream>
#include <string>

// Returns "true" if all digits after dot are nulls
constexpr bool isAllDigitsAfterDotAreNulls(const std::string &str)
{
    for (size_t i{str.find('.') + 1UL}; i < str.length(); i++)
    {
        if (str.at(i) not_eq '0')
            return false;
    }
    return true;
}

// Returns "true" if 'n' is even, otherwise - "false"
bool is_even(double n)
{
    std::string str{std::to_string(n)};

    if (isAllDigitsAfterDotAreNulls(str))
        return ((str.at(str.find('.') - 1UL) - '0') % 2) ? false : true;
    else
        return false;
}

#include <cmath>
bool smart_isEven(double n)
{
    return fmod(n, 2) == 0;
}

int main()
{
    std::cout << is_even(0) << std::endl;
    std::cout << is_even(0.5) << std::endl;
    std::cout << is_even(1) << std::endl;
    std::cout << is_even(2) << std::endl;
    std::cout << is_even(-4) << std::endl;
    std::cout << is_even(1.743579) << std::endl;
    std::cout << is_even(1.743578) << std::endl;

    std::cout << "\nSmart solution:" << std::endl;

    std::cout << smart_isEven(0) << std::endl;
    std::cout << smart_isEven(0.5) << std::endl;
    std::cout << smart_isEven(1) << std::endl;
    std::cout << smart_isEven(2) << std::endl;
    std::cout << smart_isEven(-4) << std::endl;
    std::cout << smart_isEven(1.743579) << std::endl;
    std::cout << smart_isEven(1.743578) << std::endl;

    return EXIT_SUCCESS;
}
