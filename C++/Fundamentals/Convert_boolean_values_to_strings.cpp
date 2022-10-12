// Task: Complete the method that takes a boolean
// value and return a "Yes" string for true, or a "No" string for false.

#include <string>
#include <iostream>

std::string bool_to_word(const bool &__value)
{
    return (__value) ? "Yes" : "No";
}

int main()
{
    std::cout << bool_to_word(true) << std::endl;
    std::cout << bool_to_word(false) << std::endl;

    return EXIT_SUCCESS;
}
