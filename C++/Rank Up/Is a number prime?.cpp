#include <iostream>
#include <cmath>

// Returns "true" if 'num' is a prime number
bool isPrime(int const &num)
{
    if (num <= 1)
        return false;

    for (int i{2}; i <= static_cast<int>(std::sqrt(num)); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    std::cout << isPrime(5) << '\t' << isPrime(4483) << '\t' << isPrime(3164)
              << '\t' << isPrime(7789) << '\t' << isPrime(1) << '\t' << isPrime(0)
              << '\t' << isPrime(4) << std::endl;

    return 0;
}
