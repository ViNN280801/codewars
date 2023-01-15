// Task: Take 2 strings s1 and s2 including only letters from a to z.
// Return a new sorted string, the longest possible,
// containing distinct letters - each taken only once -
// coming from s1 or s2.

// Examples:

// a = "xyaabbbccccdefww"
// b = "xxxxyyyyabklmopq"
// longest(a, b) -> "abcdefklmopqwxy"

// a = "abcdefghijklmnopqrstuvwxyz"
// longest(a, a) -> "abcdefghijklmnopqrstuvwxyz"

#include <iostream>
#include <string>
#include <algorithm>

class TwoToOne
{
public:
    // Returns new sorted string, the longest possible, containing distinct letters,
    // each taken only once
    static std::string longest(const std::string &__str1, const std::string &__str2)
    {
        // Adding two lines
        std::string result_str{__str1 + __str2};

        // Preliminary sorting
        std::sort(std::begin(result_str), std::end(result_str));

        // Removing all non-unique elements in the result string
        result_str.erase(std::unique(std::begin(result_str), std::end(result_str)), std::end(result_str));

        // Sorting it
        std::sort(std::begin(result_str), std::end(result_str));

        // Returning the result
        return result_str;
    }
};

int main()
{
    TwoToOne obj;
    std::cout << obj.longest("aaaaaaaaaaaabdaf", "tttttttttttttuia") << std::endl;

    return EXIT_SUCCESS;
}
