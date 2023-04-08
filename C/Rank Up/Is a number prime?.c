#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Returns "true" if passed argument 'num' is a prime number
bool is_prime(int num)
{
    if (num <= 0)
        return false;

    for (int i = 2; i <= (int)sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", is_prime(5), is_prime(4483), is_prime(3164), is_prime(7789), is_prime(1), is_prime(0));
    return 0;
}
