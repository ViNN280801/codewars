#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string_view>

std::vector<std::string> sortByLength(std::vector<std::string> array)
{
    if (array.empty())
        return std::vector<std::string>{};
    std::sort(array.begin(), array.end(), [](std::string_view a, std::string_view b)
              { return a.length() < b.length(); });
    return array;
}

int main()
{
    for (std::string_view word : sortByLength({"Telescopes", "Glasses", "Eyes", "Monocles"}))
        std::cout << word << '\n';
    return EXIT_SUCCESS;
}
