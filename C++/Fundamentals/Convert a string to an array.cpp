#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> string_to_array(std::string const &s)
{
    if (s.empty())
        return {""};

    std::vector<std::string> vec;
    std::string tmp;
    for (size_t i{}; i < s.length(); i++)
    {
        tmp.push_back(s.at(i));
        if (s.at(i) == ' ' || i == s.length() - 1)
        {
            if (tmp.at(tmp.length() - 1) == ' ')
                tmp.erase(std::cend(tmp) - 1);

            vec.push_back(tmp);
            tmp.clear();
        }
    }

    return vec;
}

int main()
{
    std::vector<std::string> vec{string_to_array("I love arrays they are my favorite")};
    for (auto const &el : vec)
        std::cout << el << '\n';
    vec = string_to_array("some value");
    std::endl(std::cout);
    for (auto const &el : vec)
        std::cout << el << '\n';

    return EXIT_SUCCESS;
}
