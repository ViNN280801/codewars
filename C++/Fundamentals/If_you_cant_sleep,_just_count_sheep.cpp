// Task: Given a non-negative integer, 3 for example, return a string with a
// murmur: "1 sheep...2 sheep...3 sheep...". Input will always be valid, i.e. no negative integers.

#include <iostream>
#include <string>

std::string countSheep(int number)
{
    std::string str("");

    for(int i{1}; i <= number; i++)
    {
        str += std::to_string(i) + " sheep...";
    }

    return str;
}

int main()
{
    std::cout << countSheep(0) << std::endl;
    std::cout << countSheep(1) << std::endl;
    std::cout << countSheep(2) << std::endl;
    std::cout << countSheep(3) << std::endl;
    std::cout << countSheep(4) << std::endl;
    std::cout << countSheep(5) << std::endl;

    return EXIT_SUCCESS;
}
