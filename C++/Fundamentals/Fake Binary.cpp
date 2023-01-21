// Task: Given a string of digits, you should replace any digit below 5 with '0'
// and any digit 5 and above with '1'. Return the resulting string.

// Note: input will never be an empty string

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

std::string fakeBin(std::string str)
{
    std::replace_if(std::begin(str), std::end(str), [](const char &el) { return el < '5'; }, '0');
    std::replace_if(std::begin(str), std::end(str), [](const char &el) { return el not_eq '0'; }, '1');
    return str;
}

int main()
{
    std::cout << fakeBin("45385593107843568") << std::endl;
    std::cout << fakeBin("509321967506747") << std::endl;
    std::cout << fakeBin("366058562030849490134388085") << std::endl;
    std::cout << fakeBin("15889923") << std::endl;
    std::cout << fakeBin("800857237867") << std::endl;

    return EXIT_SUCCESS;
}
