// Task: Complete the function that accepts a string parameter, and
// reverses each word in the string. All spaces in the string should be retained.

// Examples
// "This is an example!" ==> "sihT si na !elpmaxe"
// "double  spaces"      ==> "elbuod  secaps"

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

// Returns vector of words in a string, except any spaces
std::vector<std::string> split_str(const std::string &__str, const std::string &__delimiter = " ")
{
    std::vector<std::string> splitted_str;
    std::string str(__str);

    // Splitting string on words
    size_t pos{str.find(__delimiter)}, initial_pos{0UL};
    while (pos != std::string::npos)
    {
        splitted_str.push_back(str.substr(initial_pos, pos - initial_pos));
        initial_pos = pos + 1UL;
        pos = str.find(__delimiter, initial_pos);
    }

    // Adding last word
    splitted_str.push_back(str.substr(initial_pos, std::min(pos, str.size()) - initial_pos + 1));

    return splitted_str;
}

std::string reverse_words(std::string str)
{
    std::vector<std::string> splitted{split_str(str)};
    std::string reversed("");

    for (auto word : splitted)
    {
        std::reverse(std::begin(word), std::end(word));
        reversed += word + " ";
    }
    reversed.erase(std::cend(reversed) - 1);

    return reversed;
}

int main()
{
    std::cout << reverse_words("The quick brown fox jumps over the lazy dog.") << std::endl;
    std::cout << reverse_words("apple") << std::endl;
    std::cout << reverse_words("a b c d") << std::endl;
    std::cout << reverse_words("double  spaced  words") << std::endl;
    std::cout << reverse_words(" Test with a leading space") << std::endl;
    std::cout << reverse_words("Test with a trailing space ") << std::endl;
    std::cout << reverse_words("") << std::endl;
    std::cout << reverse_words("ab   ba   cd") << std::endl;

    return EXIT_SUCCESS;
}
