// Task: Introduction

// The first century spans from the year 1 up to and including the year 100,
// the second century - from the year 101 up to and including the year 200, etc.
// Given a year, return the century it is in.

// Examples:
// 1705 --> 18
// 1900 --> 19
// 1601 --> 17
// 2000 --> 20

#include <iostream>

int centuryFromYear(int year)
{
    return ((year >= (((year / 100) * 100) + 1)) &&
            (year <= (((year / 100) + 1) * 100)))
               ? (year / 100) + 1
               : (year / 100);
}

int main()
{
    std::cout << centuryFromYear(1705) << std::endl;
    std::cout << centuryFromYear(1900) << std::endl;
    std::cout << centuryFromYear(1601) << std::endl;
    std::cout << centuryFromYear(2000) << std::endl;
    std::cout << centuryFromYear(8799) << std::endl;
    std::cout << centuryFromYear(8800) << std::endl;
    std::cout << centuryFromYear(8801) << std::endl;
    std::cout << centuryFromYear(8898) << std::endl;
    std::cout << centuryFromYear(8899) << std::endl;
    std::cout << centuryFromYear(8900) << std::endl;
    std::cout << centuryFromYear(8901) << std::endl;

    return EXIT_SUCCESS;
}
