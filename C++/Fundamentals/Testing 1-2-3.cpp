#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> number(std::vector<std::string> const &lines)
{
    if (lines.empty())
        return {};

    std::vector<std::string> num(lines.cbegin(), lines.cend());
    for (size_t i{}; i < num.size(); i++)
        num.at(i).insert(0, std::to_string(i + 1) + ": ");
    return num;
}

int main()
{
    std::vector<std::string> v{"a", "b", "c"};
    for (auto const &el : number(v))
        std::cout << el << '\n';

    return EXIT_SUCCESS;
}
