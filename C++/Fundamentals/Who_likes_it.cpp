// You probably know the "like" system from Facebook and other pages. People can "like" blog posts,
// pictures or other items. We want to create the text that should be displayed next to such an item.

// Implement the function which takes an array containing the names of people that like an item.
// It must return the display text as shown in the examples:

// []                                -->  "no one likes this"
// ["Peter"]                         -->  "Peter likes this"
// ["Jacob", "Alex"]                 -->  "Jacob and Alex like this"
// ["Max", "John", "Mark"]           -->  "Max, John and Mark like this"
// ["Alex", "Jacob", "Mark", "Max"]  -->  "Alex, Jacob and 2 others like this"

// Note: For 4 or more names, the number in "and 2 others" simply increases

#include <iostream>
#include <string>
#include <vector>

// Returns list (represented as string) of people who like smth in social web
std::string likes(const std::vector<std::string> &names)
{
    if (names.empty())
        return "no one likes this";
    else if (names.size() == 1)
        return names.at(0UL) + " likes this";
    else if (names.size() == 2)
        return names.at(0UL) + " and " + names.at(1UL) + " like this";
    else if (names.size() == 3)
        return names.at(0UL) + ", " + names.at(1UL) + " and " + names.at(2UL) + " like this";
    else
        return names.at(0UL) + ", " + names.at(1UL) + " and " + std::to_string(names.size() - 2UL) + " others like this";
}

int main()
{
    std::cout << likes({}) << std::endl;
    std::cout << likes({"Peter"}) << std::endl;
    std::cout << likes({"Jacob", "Alex"}) << std::endl;
    std::cout << likes({"Max", "John", "Mark"}) << std::endl;
    std::cout << likes({"Alex", "Jacob", "Mark", "Max"}) << std::endl;

    return EXIT_SUCCESS;
}
