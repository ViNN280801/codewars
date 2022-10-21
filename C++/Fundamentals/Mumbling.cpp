// Task: This time no story, no theory. The examples below show you how to write function accum:

// Examples:
// accum("abcd") -> "A-Bb-Ccc-Dddd"
// accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
// accum("cwAt") -> "C-Ww-Aaa-Tttt"

// The parameter of accum is a string which includes only letters from a..z and A..Z.

#include <iostream>
#include <regex>

class Accumul
{
protected:
    // Returns true if string is consist only of letters from a..z and A..Z
    static bool is_only_letters(const std::string &__str)
    {
        return std::regex_match(__str, std::regex("[A-Za-z]+"));
    }

    // Makes all letters in '__str' uppercase
    static void str_to_upper(std::string &__str)
    {
        for (size_t index{0UL}; index < __str.size(); index++)
        {
            __str.at(index) = std::toupper(__str.at(index));
        }
    }

    // Inserts '-' between the all letters
    static void dash_insert(std::string &__str)
    {
        size_t size{__str.size()};
        for (size_t index{0UL}; index < size; index++)
        {
            if (index < size - 1UL)
                __str.insert(index + 1UL + index, "-");
        }
    }

    // Inserts symbols 'n' times, where 'n' - is index of original string
    static void repeat_insert(std::string &__str)
    {
        for (size_t index{0UL}, count{0UL}; index < __str.size(); index++)
        {
            if (!isalpha(__str.at(index)))
            {
                count++;
                std::string tmp{static_cast<char>(std::tolower(__str.at(index + 1UL)))};

                for (size_t repeat_index{0UL}; repeat_index < count; repeat_index++)
                    __str.insert(index + 2UL, tmp);
            }
        }
    }

public:
    static std::string accum(const std::string &__str)
    {
        if (!is_only_letters(__str))
            return "";

        std::string str{__str};

        str_to_upper(str);
        dash_insert(str);
        repeat_insert(str);

        return str;
    }
};

int main()
{
    std::cout << Accumul::accum("abcd") << std::endl;
    std::cout << Accumul::accum("RqaEzty") << std::endl;
    std::cout << Accumul::accum("cwAt") << std::endl;
    std::cout << Accumul::accum("ZpglnRxqenU") << std::endl;
    std::cout << Accumul::accum("NyffsGeyylB") << std::endl;

    return EXIT_SUCCESS;
}
