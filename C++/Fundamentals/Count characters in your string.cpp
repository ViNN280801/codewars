#include <map>
#include <string_view>
#include <string>

std::map<char, unsigned> count(std::string_view string)
{
    std::map<char, unsigned> m;

    for (auto const &ch : string)
        m[ch]++;

    return m;
}
