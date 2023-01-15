// Task: Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.

#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

// Moving the first letter of each word to the end of it, then adding "ay" to the end of the word. Leaving punctuation marks untouched.
std::string pig_it(std::string str)
{
    // Initializing string stream with 'str'
    std::istringstream iss(str);

    // Zeroing out 'str' for write new data into and return it in future
    str.clear();

    // Initializing vector of string which is split 'str' on words
    std::vector<std::string> words(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

    // Loop for add "ay" in each other word
    for (size_t i = 0UL; i < words.size(); i++)
    {
        // Saving first character of word
        char first_ch = words[i].at(0UL);

        // Erasing first character of word
        words[i].erase(words[i].begin());

        // Adding first character in the end of word then adding "ay" character by character
        words[i].insert(words[i].end(), first_ch);
        words[i].push_back('a');
        words[i].push_back('y');
    }

    // Loop for move punctuation in the end of word
    for (size_t i = 0UL; i < words.size(); i++)
    {
        // Char for store punctuation
        char punct{};
        for (auto it = words[i].begin(); it != words[i].end(); ++it)
        {
            // Checks that there is a punctuation mark behind 'it' iterator
            if (std::ispunct(*it))
            {
                // Saving punctuation mark
                punct = *it;

                // Erasing punctuation mark from this place
                words[i].erase(it);

                // Adding 'punct' to the end for word
                words[i].push_back(punct);
            }
        }
    }

    // Filling string with words from vector of strings using for_each loop
    for (const auto &word : words)
    {
        str += word + " ";
    }

    // Erasing excess space in the end of 'str' string
    str.erase(str.end() - 1);

    // Moving punctuation mark to 1 symbol if this mark is in the end of string
    if (std::ispunct(str[str.length() - 1]))
    {
        str.insert(str.length() - 1, " ");
    }

    // Loop for remove "ay" connected to punctuation mark
    for (auto it = str.begin(); it != str.end(); it++)
    {
        if (std::ispunct(*it) and std::isspace(*(it - 3)))
        {
            str.erase(it - 1);
            str.erase(it - 2);
        }
    }

    // Remember last punctuation mark if such exist
    char last_mark{};
    if (std::ispunct(str[str.length() - 1]))
    {
        last_mark = str[str.length() - 1];
    }

    // Removing secluded "ay" symbols
    if (str.find(" ay ") != std::string::npos)
    {
        str.erase(str.find(" ay "), str.size());

        // Adding last punctuation mark to the end of sentence
        str.push_back(' ');
        str.push_back(last_mark);
    }

    // Removing "ay" if these symbols are in the beginning of the sentence
    if (str[0] == 'a' and str[1] == 'y')
    {
        str.erase(0, 2);
    }

    // If sentence begins from punctuation mark with a space in the front of this mark
    if (str[0] == ' ')
    {
        str.erase(0, 1);
    }

    // Returning modernized string
    return str;
}

// Clever solution
#include <regex>
// Moving the first letter of each word to the end of it, then adding "ay" to the end of the word. Leaving punctuation marks untouched.
std::string pig_it_clever(std::string str)
{
    // The solution is presented using regular expressions
    std::regex reg(("(\\w)(\\w*)(\\s|$)"));
    return std::regex_replace(str, reg, "$2$1ay$3");
}

int main(int argc, char *argv[])
{
    std::cout << "Experiment #1: " << std::endl;
    std::cout << pig_it("Pig, latin! is cool") << std::endl;
    std::cout << pig_it("Hello : World!") << std::endl;
    std::cout << pig_it("This; is my_ string +") << std::endl;
    std::cout << pig_it("Special . ! string -") << std::endl;
    std::cout << pig_it("! Foocking string") << std::endl;
    std::cout << pig_it(".") << std::endl;

    std::cout << std::endl << "Experiment #2: " << std::endl;
    std::cout << pig_it_clever("Pig, latin! is cool") << std::endl;
    std::cout << pig_it_clever("Hello : World!") << std::endl;
    std::cout << pig_it_clever("This; is my_ string +") << std::endl;
    std::cout << pig_it_clever("Special . ! string -") << std::endl;
    std::cout << pig_it_clever("! Foocking string") << std::endl;
    std::cout << pig_it_clever(".") << std::endl;

    return EXIT_SUCCESS;
}