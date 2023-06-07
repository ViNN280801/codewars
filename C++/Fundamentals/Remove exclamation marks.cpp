#include <string>
#include <algorithm>
#include <iterator>

std::string removeExclamationMarks(std::string str)
{
    str.erase(std::remove(std::begin(str), std::end(str), '!'), std::cend(str));
    return str;
}

#include <regex>

std::string removeExclamationMarks(std::string str)
{
    return std::regex_replace(str, std::regex("!"), "");
}
