// Task: Given a random non-negative number, you have to return
// the digits of this number within an array in reverse order.

// Example(Input => Output):
// 35231 => [1,3,2,5,3]
// 0 => [0]

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

int main()
{
    std::vector<int> vec{split_number_on_digits(12345)};

    auto print_vec{[&vec]
                   {
                       for (const auto &digit : vec)
                       {
                           std::cout << digit << ' ';
                       }
                       endl(std::cout);
                   }};
    print_vec();

    return EXIT_SUCCESS;
}
