// Task:

// Description:
// You are going to be given a word. Your job is to return the
// middle character of the word. If the word's length is odd,
// return the middle character. If the word's length is even,
// return the middle 2 characters.

// Examples:
// Kata.getMiddle("test") should return "es"
// Kata.getMiddle("testing") should return "t"
// Kata.getMiddle("middle") should return "dd"
// Kata.getMiddle("A") should return "A"

// Input
// A word (string) of length 0 < str < 1000 (In javascript you may get
// slightly more than 1000 in some test cases due to an error in the test cases).
// You do not need to test for this. This is only here to tell you that you
// do not need to worry about your solution timing out.

// Output
// The middle character(s) of the word represented as a string.

#include <iostream>
#include <string>

// Returning the middle of the '__input' string
std::string get_middle(std::string __input)
{
    if (__input.size() <= 1)
        return __input;

    std::string middle{__input.at((__input.size() / 2) - 1UL)};
    middle.push_back(__input.at((__input.size() / 2)));

    return (__input.size() % 2 == 0) ? middle : std::string(1, __input.at((__input.size() / 2)));
}

int main()
{
    std::cout << get_middle("test") << std::endl;
    std::cout << get_middle("testing") << std::endl;

    return EXIT_SUCCESS;
}
