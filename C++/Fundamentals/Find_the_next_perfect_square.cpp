// Task: You might know some pretty large perfect squares.
// But what about the NEXT one?

// Complete the findNextSquare method that finds the next integral
// perfect square after the one passed as a parameter. Recall
// that an integral perfect square is an integer n such that sqrt(n) is also an integer.

// If the parameter is itself not a perfect square then -1 should be returned.
// You may assume the parameter is non-negative.

// Examples:(Input --> Output)
// 121 --> 144
// 625 --> 676
// 114 --> -1 since 114 is not a perfect square

#include <iostream>
#include <cmath>

// Returns 'true' if sqrt of '__number' is not irrational
bool is_sqrt_integer(const long int &__number)
{
    if (int sq{static_cast<int>(sqrt(__number))}; pow(sq, 2.0) != __number)
        return false;
    else
        return true;
}

// Returns next number if which is squared we will get next square number
long int get_next_sqrt_number(const long int &__number)
{
    return static_cast<int>(sqrt(__number)) + 1L;
}

// Returns '-1' if 'sq' is not a perfect square
// In other cases returns next square
long int findNextSquare(const long int &__number)
{
    if (!is_sqrt_integer(__number))
        return -1;

    return pow(get_next_sqrt_number(__number), 2.0);
}

int main()
{
    std::cout << findNextSquare(121) << std::endl;
    std::cout << findNextSquare(625) << std::endl;
    std::cout << findNextSquare(319225) << std::endl;
    std::cout << findNextSquare(15241383936) << std::endl;
    std::cout << findNextSquare(155) << std::endl;

    return EXIT_SUCCESS;
}
