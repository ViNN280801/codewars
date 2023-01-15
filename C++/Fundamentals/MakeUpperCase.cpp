// Task: Write a function which converts the input string to uppercase.

#include <iostream>

// Makes all characters in string to uppercase
std::string str_to_upper(const std::string &__str)
{
    std::string str{__str};

    for (size_t index{0UL}; index < __str.size(); index++)
    {
        str.at(index) = std::toupper(str.at(index));
    }

    return str;
}

int main()
{
    std::cout << str_to_upper("hello") << std::endl;

    return EXIT_SUCCESS;
}
