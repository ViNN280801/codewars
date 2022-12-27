// Your job is to write a function which increments a string, to create a new string.

// If the string already ends with a number, the number should be incremented by 1.
// If the string does not end with a number. the number 1 should be appended to the new string.

// Examples:
// foo -> foo1
// foobar23 -> foobar24
// foo0042 -> foo0043
// foo9 -> foo10
// foo099 -> foo100

// Attention: If the number has leading zeros the amount of digits should be considered.

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

// Returns "true" if string contains at least one digit
// "false" - otherwise
constexpr bool isNoDigits(const std::string &str)
{
    for (const auto &el : str)
    {
        if (isdigit(el))
            return false;
    }
    return true;
}

// Returns string and last digits as a pair of values
// Example: "fo99obar99" -> "fo99obar" and "99"
std::pair<std::string, int> separateStrFromLastDigits(std::string str)
{
    std::string lastDigits;
    for (size_t i{str.length() - 1UL}; i == 0UL; i--)
    {
        // Adding to temporaly string only last digits
        if (isdigit(str.at(i)))
        {
            lastDigits.push_back(str.at(i));
            str.erase(i);
        }
        else
            break;
    }
    std::reverse(std::begin(lastDigits), std::end(lastDigits));
    int digits(std::stoi(lastDigits));

    return std::make_pair(str, digits);
}

// Returns string with incremented value in the end
std::string incrementString(const std::string &str)
{
    // If string is empty or if it don't has digits
    if (str.empty() or isNoDigits(str))
        return str + "1";
    // If the last character in string is 0 -> return substring [0; end],
    // where str.at(end) replaces to 1
    else if (*(std::end(str) - 1) == '0')
        return str.substr(0UL, str.length() - 1UL) + "1";
    else
        return str;
}

int main()
{
    std::cout << incrementString("foobar000") << std::endl;
    std::cout << incrementString("foo") << std::endl;
    std::cout << incrementString("foobar001") << std::endl;
    std::cout << incrementString("foobar99") << std::endl;
    std::cout << incrementString("foobar099") << std::endl;
    std::cout << incrementString("") << std::endl;
    std::cout << incrementString("foobar069") << std::endl;
    std::cout << incrementString("foobar45") << std::endl;
    std::cout << incrementString("f0o0o0b0a0r0099") << std::endl;
    std::cout << incrementString("foo99999") << std::endl;
    std::cout << incrementString("foo099999") << std::endl;
    std::cout << incrementString("f0o0o0b0a0r00990") << std::endl;
    std::cout << incrementString("fo99obar99") << std::endl;

    std::cout << separateStrFromLastDigits("fo99obar99").first << '\t'
              << separateStrFromLastDigits("fo99obar99").second << std::endl;

    return EXIT_SUCCESS;
}
