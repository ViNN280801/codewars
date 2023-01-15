// Your function takes two arguments:

// current father's age (years)
// current age of his son (years)

// Сalculate how many years ago the father was twice as old as
// his son (or in how many years he will be twice as old).
// The answer is always greater or equal to 0, no matter if it was in the past or it is in the future.

#include <iostream>
#include <concepts>

template <std::integral T>
constexpr T twice_as_old(T dad, T son)
{
    return (dad - son * 2) < 0 ? ((dad - son * 2) * (-1)) : (dad - son * 2);
}

template <std::integral T>
constexpr T smart_twice_as_old(T dad, T son)
{
    return abs(dad - 2 * son);
}

int main()
{
    std::cout << twice_as_old(36, 7) << std::endl;
    std::cout << twice_as_old(55, 30) << std::endl;
    std::cout << twice_as_old(42, 21) << std::endl;
    std::cout << twice_as_old(22, 1) << std::endl;
    std::cout << twice_as_old(29, 0) << std::endl;

    std::cout << "\nSmart sln:" << std::endl;
    std::cout << smart_twice_as_old(36, 7) << std::endl;
    std::cout << smart_twice_as_old(55, 30) << std::endl;
    std::cout << smart_twice_as_old(42, 21) << std::endl;
    std::cout << smart_twice_as_old(22, 1) << std::endl;
    std::cout << smart_twice_as_old(29, 0) << std::endl;

    return EXIT_SUCCESS;
}
