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
// Caught std::exception: what(): std::stoi()
// Do not solve problem with big numbers
/*
#include <algorithm>
#include <iterator>

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

// Returns count of digits in the number 'n'
constexpr int countDigits(int n)
{
    if (n / 10 == 0)
        return 1;
    return 1 + countDigits(n / 10);
}

// Returns string and last digits as a pair of values
// Trailing nils are accounted
// Example: "fo99obar99" -> "fo99obar" and "99"
// "fo99obar099" -> "fo99obar0" and "99"
std::pair<std::string, unsigned long long> separateStrFromLastDigits(std::string str)
{
    std::string lastDigits;
    size_t pos{str.length() - 1UL};
    while (pos != 0UL)
    {
        // Adding to temporaly string only last digits
        if (isdigit(str.at(pos)))
        {
            lastDigits.push_back(str.at(pos));
            // Erasing added number, to pass only string without last digits to pair
            str.erase(pos);
        }
        // Breaking the loop when met character
        // to avoid iteration in all string
        else
            break;

        pos--;
    }
    std::reverse(std::begin(lastDigits), std::end(lastDigits));

    // Counting trailing nils
    int nilCounter{0};
    for (const auto &dig : lastDigits)
    {
        if (dig == '0')
            nilCounter++;
        else
            break;
    }

    // Adding trailing nils to 'str'
    while (nilCounter != 0)
    {
        str.push_back('0');
        nilCounter--;
    }

    return std::make_pair(str, std::stoull(lastDigits));
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
    {
        if ((*(std::cend(separateStrFromLastDigits(str).first) - 1) == '0') and
            (countDigits(separateStrFromLastDigits(str).second) <
             countDigits(separateStrFromLastDigits(str).second + 1)))
            return separateStrFromLastDigits(str).first.substr(0UL, str.length() - countDigits(separateStrFromLastDigits(str).second) - 1UL) +
                   std::to_string(separateStrFromLastDigits(str).second + 1);
        else
            return separateStrFromLastDigits(str).first +
                   std::to_string(separateStrFromLastDigits(str).second + 1);
    }
}
*/

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

// Returns count of 9 digit in the string 'str'
constexpr size_t countOfLast9InStr(const std::string &str)
{
    size_t count{0};
    for (auto it{std::crbegin(str)}; it != std::crend(str); ++it)
    {
        if (*it == '9')
            count++;
        else
            break;
    }
    return count;
}

// Returns string with incremented value in the end
std::string incrementString(const std::string &str)
{
    // If string is empty or if it don't has digits
    if (str.empty() or isNoDigits(str))
        return str + "1";
    else
    {
        if ((*(std::cend(str) - 1) - '0') < 9)
            return str.substr(0UL, str.length() - 1UL) + std::to_string(((*(std::cend(str) - 1) - '0') + 1));
        else if (countOfLast9InStr(str) == str.length())
        {
            size_t count{countOfLast9InStr(str)};
            std::string result{'1'};
            while (count != 0)
            {
                result.push_back('0');
                count--;
            }
            return result;
        }
        else
        {
            std::string copy{str};
            size_t count{countOfLast9InStr(copy)}, pos{copy.length() - 1UL};

            while (count != 0UL)
            {
                copy.erase(pos);
                count--;
                pos--;
            }

            if ((copy.at(pos) != '9') and ((copy.at(pos) - '0') < 9))
            {
                copy.at(pos) = (((copy.at(pos) - '0') + 1) + '0');

                count = countOfLast9InStr(str);
                while (count != 0UL)
                {
                    copy.push_back('0');
                    count--;
                }
                return copy;
            }
            else
            {
                count = countOfLast9InStr(str);
                copy.push_back('1');
                while (count != 0UL)
                {
                    copy.push_back('0');
                    count--;
                }
                return copy;
            }
        }
    }
}

int main()
{
    std::cout << incrementString("foobar000") << std::endl;
    std::cout << incrementString("foo") << std::endl;
    std::cout << incrementString("foobar001") << std::endl;
    std::cout << incrementString("foobar99") << std::endl;
    std::cout << incrementString("foobar099") << std::endl;
    std::cout << incrementString("9999") << std::endl;
    std::cout << incrementString("") << std::endl;
    std::cout << incrementString("foobar069") << std::endl;
    std::cout << incrementString("foobar45") << std::endl;
    std::cout << incrementString("f0o0o0b0a0r0099") << std::endl;
    std::cout << incrementString("foo99999") << std::endl;
    std::cout << incrementString("foo099999") << std::endl;
    std::cout << incrementString("f0o0o0b0a0r00990") << std::endl;
    std::cout << incrementString("fo99obar99") << std::endl;
    std::cout << incrementString("ryxjlgupeqyiobhlpswz050") << std::endl;
    std::cout << incrementString("0081745667") << std::endl;
    std::cout << incrementString("uuycxdvcpxqwrbmwxjbdtirudovwasjy405") << std::endl;
    std::cout << incrementString("999999999999999999999999999999") << std::endl;

    return EXIT_SUCCESS;
}
