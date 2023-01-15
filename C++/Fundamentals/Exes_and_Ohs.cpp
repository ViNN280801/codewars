// Task:
// Check to see if a string has the same amount of 'x's and 'o's. The method must return a boolean and be
// case insensitive. The string can contain any char.

// Examples input/output:
// XO("ooxx") => true
// XO("xooxx") => false
// XO("ooxXm") => true
// XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
// XO("zzoo") => false

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

constexpr bool XO(const std::string &str)
{
    if (std::count_if(std::cbegin(str), std::cend(str), [](const char &ch)
                      { return (ch == 'o') or (ch == 'O'); }) not_eq
        std::count_if(std::cbegin(str), std::cend(str), [](const char &ch)
                      { return ch == 'x' or (ch == 'X'); }))
        return false;

    return true;
}

int main()
{
    // static_assert(XO("ooxx") == true);
    // static_assert(XO("xooxx") == false);
    // static_assert(XO("ooxXm") == true);
    // static_assert(XO("zpzpzpp") == true);
    // static_assert(XO("zzoo") == false);

    std::cout << XO("ooxx") << std::endl;
    std::cout << XO("xooxx") << std::endl;
    std::cout << XO("ooxXm") << std::endl;
    std::cout << XO("zpzpzpp") << std::endl;
    std::cout << XO("zzoo") << std::endl;

    return EXIT_SUCCESS;
}
