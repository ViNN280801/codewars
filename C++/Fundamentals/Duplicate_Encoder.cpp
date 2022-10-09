// Task: The goal of this exercise is to convert a string to a new string where
// each character in the new string is "(" if that character
// appears only once in the original string, or ")" if
// that character appears more than once in the original string.
// Ignore capitalization when determining if a character is a duplicate.

// Examples:
// "din"      =>  "((("
// "recede"   =>  "()()()"
// "Success"  =>  ")())())"
// "(( @"     =>  "))(("

// Notes
// Assertion messages may be unclear about what they display in
// some languages. If you read "...It Should encode XXX",
// the "XXX" is the expected result, not the input!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <span>

void print_vec(std::span<const size_t> __vec)
{
    for (auto &elem : __vec)
    {
        std::cout << elem << ' ';
    }
    endl(std::cout);
}

// Returns string with all lowercase characters
std::string to_lower(const std::string &__str)
{
    std::string result;

    for (auto &ch : __str)
    {
        result.push_back(static_cast<char>(std::tolower(ch)));
    }

    return result;
}

std::vector<size_t> get_indeces_of_same_elems(const std::string &__str)
{
    std::string str_copy{to_lower(__str)};
    std::vector<size_t> indeces_vec;

    for (size_t i{0UL}; i < str_copy.size(); i++)
    {
        if (str_copy.at(0UL) == str_copy.at(i) && i != 0UL)
            indeces_vec.push_back(0UL);

        for (size_t j{0UL}; j < str_copy.size(); j++)
        {
            if (str_copy.at(i) == str_copy.at(j) && i != j)
                indeces_vec.push_back(i);
        }
    }

    std::sort(std::begin(indeces_vec), std::end(indeces_vec));
    indeces_vec.erase(std::unique(std::begin(indeces_vec), std::end(indeces_vec)), std::cend(indeces_vec));

    return indeces_vec;
}

// Returns string where
// each character in the new string is "(" if that character
// appears only once in the original string, or ")" if
// that character appears more than once in the original string.
std::string duplicate_encoder(const std::string &__word)
{
    std::string result{__word};
    std::vector<size_t> indeces_of_same(get_indeces_of_same_elems(__word));

    for (size_t i{0UL}; i < __word.size(); i++)
    {
        if (result.at(i) == ')' || isascii(static_cast<char>(result.at(i))))
            result.at(i) = '(';

        for (auto &index_of_same : indeces_of_same)
        {
            if (i == index_of_same)
                result.replace(i, 1UL, ")");
        }
    }

    return result;
}

int main()
{
    std::cout << duplicate_encoder("din") << std::endl;
    std::cout << duplicate_encoder("recede") << std::endl;
    std::cout << duplicate_encoder("Success") << std::endl;
    std::cout << duplicate_encoder("CodeWarrior") << std::endl;
    std::cout << duplicate_encoder("(( @") << std::endl;
    std::cout << duplicate_encoder(" ( ( )") << std::endl;

    return EXIT_SUCCESS;
}
