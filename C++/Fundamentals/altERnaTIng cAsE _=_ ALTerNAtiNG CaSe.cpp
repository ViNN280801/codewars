#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

std::string to_alternating_case(const std::string &str)
{
    std::string res{str};
    std::transform(std::cbegin(str), std::cend(str), std::begin(res), [](const auto &el)
                   { return isupper(el) ? tolower(el) : toupper(el); });
    return res;
}

int main()
{
    std::cout << to_alternating_case("hello world") << std::endl;
    std::cout << to_alternating_case("HELLO WORLD") << std::endl;
    std::cout << to_alternating_case("hello WORLD") << std::endl;
    std::cout << to_alternating_case("HeLLo WoRLD") << std::endl;
    std::cout << to_alternating_case("12345") << std::endl;
    std::cout << to_alternating_case("1a2b3c4d5e") << std::endl;
    std::cout << to_alternating_case("String.prototype.toAlternatingCase") << std::endl;
    std::cout << to_alternating_case("Hello World") << std::endl;
    std::cout << to_alternating_case("altERnaTIng cAsE") << std::endl;
    std::cout << to_alternating_case("ALTerNAtiNG CaSe") << std::endl;
    std::cout << to_alternating_case("altERnaTIng cAsE <=> ALTerNAtiNG CaSe") << std::endl;
    std::cout << to_alternating_case("ALTerNAtiNG CaSe <=> altERnaTIng cAsE") << std::endl;

    return EXIT_SUCCESS;
}
