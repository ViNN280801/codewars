#include <string>
#include <algorithm>
#include <iterator>

std::string replaceAll(std::string str)
{
    str.erase(std::find(std::cbegin(str), std::cend(str), '#'), std::cend(str));
    return str;
}

std::string replaceAll_clever(std::string str)
{
    return str.substr(0, str.find('#'));
}
