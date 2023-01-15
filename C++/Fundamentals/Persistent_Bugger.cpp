// Task: Write a function, persistence, that takes in a positive parameter num and returns
// its multiplicative persistence, which is the number of times you must multiply
// the digits in num until you reach a single digit.

// For example (Input --> Output):
// 39 --> 3 (because 3*9 = 27, 2*7 = 14, 1*4 = 4 and 4 has only one digit)
// 999 --> 4 (because 9*9*9 = 729, 7*2*9 = 126, 1*2*6 = 12, and finally 1*2 = 2)
// 4 --> 0 (because 4 is already a one-digit number)

#include <iostream>
#include <vector>

// Returns array of digits in descending order
// from integer and non-negative type of number
template <typename unumeric_t>
std::vector<int> split_number_on_digits(const unumeric_t &__number)
{
    std::vector<int> digits;
    unumeric_t number_copy{__number};

    while (true)
    {
        digits.push_back(number_copy % 10);
        number_copy /= 10;

        if (number_copy == 0)
            return digits;
    }
}

// Returns its multiplicative persistence, which is the number of times you must multiply
// the digits in num until you reach a single digit
int persistence(const long long &__n)
{
    std::vector<int> vec{split_number_on_digits(__n)};
    int count{0};

    while (vec.size() != 1UL)
    {
        int product{1};

        for (auto it{std::cbegin(vec)}; it != std::cend(vec); ++it)
        {
            product *= *it;
        }
        vec.clear();
        vec = split_number_on_digits(product);
        count++;
    }

    return count;
}

int main()
{
    std::cout << persistence(39) << std::endl;
    std::cout << persistence(4) << std::endl;
    std::cout << persistence(25) << std::endl;
    std::cout << persistence(999) << std::endl;
    std::cout << persistence(444) << std::endl;

    return EXIT_SUCCESS;
}
