#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

size_t count_sheep(const bool sheep[], size_t count)
{
    size_t counter = 0UL;
    for (size_t i = 0UL; i < count; i++)
    {
        if (sheep[i] == true)
            counter++;
    }

    return counter;
}

int main()
{
    const bool sheep[] = {true, true, true, false,
                          true, true, true, true,
                          true, false, true, false,
                          true, false, false, true,
                          true, true, true, true,
                          false, false, true, true};

    printf("%ld\n", count_sheep(sheep, 24));
    return 0;
}