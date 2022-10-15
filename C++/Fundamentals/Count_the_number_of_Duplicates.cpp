// Task: Write a function that will return the count of distinct
// case-insensitive alphabetic characters and numeric digits that
// occur more than once in the input string. The input string
// can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.

// Example
// "abcde" -> 0 # no characters repeats more than once
// "aabbcde" -> 2 # 'a' and 'b'
// "aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
// "indivisibility" -> 1 # 'i' occurs six times
// "Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
// "aA11" -> 2 # 'a' and '1'
// "ABBA" -> 2 # 'A' and 'B' each occur twice

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Turning all characters in string to lowercase
std::string str_to_lower(const char *__str)
{
    std::string str{__str};

    for (size_t index{0UL}; index < str.size(); index++)
    {
        str.at(index) = tolower(str.at(index));
    }

    return str;
}

// Returns count of distinct case-insensitive alphabetic 
// characters and numeric digits that
// occur more than once in the input string
size_t duplicateCount(const char *in)
{
    // Set all characters in string to lowercase
    std::string str{str_to_lower(in)};

    // Sorting string
    std::sort(std::begin(str), std::end(str));

    // Iterating by each element in string
    for (size_t index{0UL}; index < str.size(); index++)
    {
        // Removing all non-unique symbols to leave only duplicates
        while (str[index] != str[index + 1UL])
            str.erase(index, 1UL);
    }

    // Removing all duplicates except for one
    str.erase(std::unique(std::begin(str), std::end(str)), std::cend(str));
    return str.size();
}

int main()
{
    std::cout << duplicateCount(" ") << std::endl;
    std::cout << duplicateCount("") << std::endl;
    std::cout << duplicateCount("aabbcde") << std::endl;
    std::cout << duplicateCount("aabBcde") << std::endl;
    std::cout << duplicateCount("Indivisibility") << std::endl;
    std::cout << duplicateCount("Indivisibilities") << std::endl;
    std::cout << duplicateCount("ABBA") << std::endl;
    std::cout << duplicateCount("This Is a StRinG") << std::endl;

    return EXIT_SUCCESS;
}
