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

// Returns last digit from string 'str' if it not a null
constexpr int getLastDigitIfNotNull(const std::string &str)
{
    int lastDigit{0};
    size_t dotPos{str.find('.')}, pos{dotPos};
    while ((pos < str.length()) and (str.at(pos) not_eq '0'))
    {
        lastDigit = str.at(pos) - '0';
        pos++;
    }
    return lastDigit;
}

// Returns "true" if 'n' is even, otherwise - "false"
bool is_even(double n)
{
    std::string str{std::to_string(n)};

    if (isAllDigitsAfterDotAreNulls(str))
        return ((str.at(str.find('.') - 1UL) - '0') % 2) ? false : true;
    else
        return (getLastDigitIfNotNull(str) % 2) ? false : true;
}

int main()
{
    std::cout << is_even(0) << std::endl;
    std::cout << is_even(0.5) << std::endl;
    std::cout << is_even(1) << std::endl;
    std::cout << is_even(2) << std::endl;
    std::cout << is_even(-4) << std::endl;

    return EXIT_SUCCESS;
}
