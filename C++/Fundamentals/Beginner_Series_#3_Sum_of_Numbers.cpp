// Task: Given two integers a and b, which can be positive or negative, find the
// sum of all the integers between and including them and return it. If the
// two numbers are equal return a or b.

// Note: a and b are not ordered!

// Examples (a, b) --> output (explanation)
// (1, 0) --> 1 (1 + 0 = 1)
// (1, 2) --> 3 (1 + 2 = 3)
// (0, 1) --> 1 (0 + 1 = 1)
// (1, 1) --> 1 (1 since both are same)
// (-1, 0) --> -1 (-1 + 0 = -1)
// (-1, 2) --> 2 (-1 + 0 + 1 + 2 = 2)

#include <iostream>

std::pair<int, int> get_less_and_greater_numbers(const int &__value1, const int &__value2)
{
    int less_number{0}, greater_number{0};
    if (__value1 == __value2)
        return std::make_pair(__value1, __value2);

    if (__value1 < __value2)
    {
        less_number = __value1;
        greater_number = __value2;
    }
    else
    {
        less_number = __value2;
        greater_number = __value1;
    }

    return std::make_pair(less_number, greater_number);
}

int sum(const int &__less = 0, const int &__great = 10)
{
    int sum{0};

    for (int i{__less}; i <= __great; i++)
    {
        sum += i;
    }

    return sum;
}

int get_sum(int a, int b)
{
    if (a == b)
        return a;

    std::pair<int, int> less_and_great{get_less_and_greater_numbers(a, b)};
    return sum(less_and_great.first, less_and_great.second);
}

int main()
{
    std::cout << get_sum(0, -1) << std::endl;
    std::cout << get_sum(0, 1) << std::endl;
    std::cout << get_sum(1, 0) << std::endl;
    std::cout << get_sum(1, 2) << std::endl;
    std::cout << get_sum(0, 1) << std::endl;
    std::cout << get_sum(1, 1) << std::endl;
    std::cout << get_sum(-1, 0) << std::endl;
    std::cout << get_sum(-1, 2) << std::endl;

    return EXIT_SUCCESS;
}
