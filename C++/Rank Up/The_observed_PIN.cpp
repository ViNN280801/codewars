// Task: Alright, detective, one of our colleagues successfully observed our target person, Robby the robber.
// We followed him to a secret warehouse, where we assume to find all the stolen stuff.
// The door to this warehouse is secured by an electronic combination lock. Unfortunately
// our spy isn't sure about the PIN he saw, when Robby entered it.

// The keypad has the following layout:

// ┌───┬───┬───┐
// │ 1 │ 2 │ 3 │
// ├───┼───┼───┤
// │ 4 │ 5 │ 6 │
// ├───┼───┼───┤
// │ 7 │ 8 │ 9 │
// └───┼───┼───┘
//     │ 0 │
//     └───┘
// He noted the PIN 1357, but he also said, it is possible that each of the digits he saw
// could actually be another adjacent digit (horizontally or vertically, but not diagonally).
// E.g. instead of the 1 it could also be the 2 or 4. And instead of the 5 it could also be the 2, 4, 6 or 8.

// He also mentioned, he knows this kind of locks. You can enter an unlimited amount of wrong
// PINs, they never finally lock the system or sound the alarm. That's why we can try out all possible (*) variations.

// * possible in sense of: the observed PIN itself and all variations
// considering the adjacent digits

// Can you help us to find all those variations? It would be nice to have a
// function, that returns an array (or a list in Java/Kotlin and C#) of all
// variations for an observed PIN with a length of 1 to 8 digits. We could name
// the function getPINs (get_pins in python, GetPINs in C#). But please note that
// all PINs, the observed one and also the results, must be strings, because of
// potentially leading '0's. We already prepared some test cases for you.

// Detective, we are counting on you!

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <map>

static const std::map<char, std::string> keypad = {
    {'0', "08"},
    {'1', "124"},
    {'2', "1235"},
    {'3', "236"},
    {'4', "1457"},
    {'5', "24568"},
    {'6', "3569"},
    {'7', "478"},
    {'8', "05789"},
    {'9', "689"}};

inline bool is_more1_less8_symbols(const std::string &__str)
{
    return (__str.length() >= 1UL && __str.length() <= 8UL) ? true : false;
}

inline bool is_digits(const std::string &__str)
{
    return __str.find_first_not_of("0123456789") == std::string::npos;
}

void get_pin(std::string __observed, std::string __cur, const size_t &__pos, std::vector<std::string> &__pins)
{
    std::string variations{keypad.at(__observed.at(__pos))};

    for (char c : variations)
    {
        if (__pos < __observed.size() - 1UL)
            get_pin(__observed, __cur + c, __pos + 1UL, __pins);
        else
            __pins.push_back(__cur + c);
    }
}

std::vector<std::string> get_pins(std::string __str)
{
    std::vector<std::string> possible_pins;

    if (is_more1_less8_symbols(__str) && is_digits(__str))
    {
        get_pin(__str, "", 0UL, possible_pins);
    }

    return possible_pins;
}

template <typename T>
void print_vec(const std::vector<T> &__vec)
{
    for (auto it{std::cbegin(__vec)}; it != std::cend(__vec); ++it)
    {
        std::cout << *it << std::endl;
    }
}

int main()
{
    std::vector<std::string> vec{get_pins("369")};
    std::cout << "Size of vec: " << vec.size() << std::endl;
    print_vec<std::string>(vec);

    return EXIT_SUCCESS;
}
