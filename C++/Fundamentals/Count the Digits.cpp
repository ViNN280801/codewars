#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <cmath>

class CountDig
{
public:
    static int nbDig(int n, int d)
    {
        std::string str{};
        for (int i{0}; i <= n; i++)
        {
            str += std::to_string(static_cast<int>(i * i));
        }
        return std::count_if(std::cbegin(str), std::cend(str), [&](char const &ch)
                             { return ch == (d + '0'); });
    }

    static int nbDig_clever(int n, int d)
    {
        std::string digits;
        for (int k = 0; k <= n; ++k)
            digits += std::to_string(k * k);

        return std::count(digits.begin(), digits.end(), std::to_string(d)[0]);
    }
};

int main()
{
    std::cout << CountDig::nbDig(10, 1) << std::endl;
    std::cout << CountDig::nbDig(25, 1) << std::endl;
    std::cout << CountDig::nbDig(5750, 0) << std::endl;

    std::cout << CountDig::nbDig_clever(10, 1) << std::endl;
    std::cout << CountDig::nbDig_clever(25, 1) << std::endl;
    std::cout << CountDig::nbDig_clever(5750, 0) << std::endl;

    return EXIT_SUCCESS;
}
