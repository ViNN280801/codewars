// Task: Welcome. In this kata, you are asked to square every digit of a number and concatenate them.

// For example, if we run 9119 through the function, 811181 will come out, because 92 is 81 and 12 is 1.
// Note: The function accepts an integer and returns an integer

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

template <typename unumeric_t>
std::vector<int> split_number_on_digits_ascending(const unumeric_t &__number)
{
    std::vector<int> digits;
    unumeric_t number_copy{__number};

    while (true)
    {
        digits.push_back(number_copy % 10);
        number_copy /= 10;

        if (number_copy == 0)
        {
            std::reverse(std::begin(digits), std::end(digits));
            return digits;
        }
    }
}

template <typename T>
T string_to_T(const std::string &__str)
{
    T value;
    std::istringstream iss(__str);
    iss >> value;
    return value;
}

int square_digits(const int &__num)
{
    std::vector<int> digits{split_number_on_digits_ascending(__num)};
    std::stringstream ss;

    for (auto it{std::cbegin(digits)}; it != std::cend(digits); ++it)
    {
        ss << *it * *it;
    }

    return string_to_T<int>(ss.str());
}

int main()
{
    std::cout << square_digits(3212) << std::endl;
    std::cout << square_digits(2112) << std::endl;
    std::cout << square_digits(0) << std::endl;
    std::cout << square_digits(13579) << std::endl;
    std::cout << square_digits(24680) << std::endl;

    return EXIT_SUCCESS;
}
