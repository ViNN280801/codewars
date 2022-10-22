// Task: Simple, remove the spaces from the string, then return the resultant string.

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

// Returns '__str' without any spaces
std::string no_space(const std::string &__str)
{
    std::string str{__str};
    str.erase(std::remove_if(std::begin(str), std::end(str), isspace), std::cend(str));
    return str;
}

int main()
{
    std::cout << no_space("8 j 8   mBliB8g  imjB8B8  jl  B") << std::endl;
    std::cout << no_space("8 8 Bi fk8h B 8 BB8B B B  B888 c hl8 BhB fd") << std::endl;
    std::cout << no_space("8aaaaa dddd r     ") << std::endl;
    std::cout << no_space("jfBm  gk lf8hg  88lbe8 ") << std::endl;
    std::cout << no_space("8j aam") << std::endl;

    return EXIT_SUCCESS;
}