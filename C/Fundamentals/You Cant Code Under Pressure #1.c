// Task: Code as fast as you can! You need to double the integer and return it.

#include <stdio.h>

// Including <stdint.h> for use types: int8_t, int16_t, int32_t etc.
#include <stdint.h>

// Returns doubled integer number
int32_t double_integer(int32_t value)
{
    return value * 2;
} 

int main(int argc, char *argv[])
{
    // Initializing number to double
    int number_to_double = 0;
    printf("Enter number which you want to double: ");
    scanf("%d", &number_to_double);
    printf("Doubled integer = %d\n", double_integer(number_to_double));

    return 0;
}