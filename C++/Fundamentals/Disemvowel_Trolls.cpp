// Task: Trolls are attacking your comment section!

// A common way to deal with this situation is to remove all of the vowels from the trolls' comments, neutralizing the threat.
// Your task is to write a function that takes a string and return a new string with all vowels removed.

// For example, the string "This website is for losers LOL!" would become "Ths wbst s fr lsrs LL!".
// Note: for this kata y isn't considered a vowel.

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <regex>

// Returns "true" if '__ch' is vowel, otherwise - "false"
bool is_vowel(const char &__ch)
{
    return (__ch == 'a' || __ch == 'e' || __ch == 'i' || __ch == 'o' ||
            __ch == 'u' || __ch == 'A' || __ch == 'E' ||
            __ch == 'I' || __ch == 'O' || __ch == 'U')
               ? true
               : false;
}

// Returns string '__str' without vowels
std::string disemvowel(const std::string &__str)
{
    std::string str(__str);
    str.erase(std::remove_if(std::begin(str), std::end(str), [](const char &ch)
                             { return is_vowel(ch); }),
              std::cend(str));
    return str;
}

// Returns string '__str' without vowels
std::string remove_vowels(const std::string &__str)
{
    std::string str(__str);
    str.erase(std::remove_if(std::begin(str), std::end(str), [](const char &ch)
                             { return is_vowel(ch); }),
              std::cend(str));
    return str;
}

// // Since C++20 (need std::erase_if())
// // Returns string '__str' without vowels
// std::string remove_vowels(const std::string &__str)
// {
//     std::string str(__str);
//     std::erase_if(str, [](const char &ch)
//                   { return is_vowel(ch); });
//     return str;
// }

// Returns string '__str' without vowels (need std::regex)
std::string regex_disemvowels(const std::string &__str)
{
    std::string str(__str);
    std::regex vowels("[aeiouAEOIOU]");
    return std::regex_replace(str, vowels, "");
}

int main()
{
    std::cout << disemvowel("This website is for losers LOL!") << std::endl;
    std::cout << regex_disemvowels("This website is for losers LOL!") << std::endl;

    return EXIT_SUCCESS;
}
