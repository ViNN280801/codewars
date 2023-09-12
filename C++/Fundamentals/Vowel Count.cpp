#include <string>
#include <algorithm>

int getCount(std::string const &s)
{
    return std::count_if(s.cbegin(), s.cend(), [&](auto const &ch)
                         { return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; });
}
