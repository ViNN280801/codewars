// Task: An isogram is a word that has no repeating letters, consecutive or
// non-consecutive. Implement a function that determines whether a string that
// contains only letters is an isogram. Assume the empty string is an isogram.
// Ignore letter case.

// Example: (Input --> Output)
// "Dermatoglyphics" --> true "aba" --> false "moOse" --> false (ignore letter case)

#include <iostream>
#include <string>
#include <algorithm>

// Turning all characters in string to lowercase
std::string str_to_lower(const char *__str)
{
    std::string str{__str};

    for (size_t index{0UL}; index < str.size(); index++)
    {
        str.at(index) = tolower(str.at(index));
    }

    return str;
}

// Returns true if '__str' is isogram, otherwise returns false
bool is_isogram(const std::string &__str)
{
    std::string str{str_to_lower(__str.c_str())};
    std::sort(std::begin(str), std::end(str));

    for (auto it{std::cbegin(str)}; it != std::cend(str); ++it)
    {
        if ((((it + 1)) != std::cend(str)) && (*it == *(it + 1)))
            return false;
    }

    return true;
}

int main()
{
    std::cout << is_isogram("Dermatoglyphics") << std::endl;
    std::cout << is_isogram("moose") << std::endl;
    std::cout << is_isogram("isIsogram") << std::endl;
    std::cout << is_isogram("") << std::endl;
    std::cout << is_isogram(" ") << std::endl;
    std::cout << is_isogram("abcdeftryu") << std::endl;

    return EXIT_SUCCESS;
}
