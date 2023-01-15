// Task: implement simple multiply function

#include <stdio.h>

// Multiplies two int numbers
int multiply(int a, int b)
{
    return a * b;
}

int main(int argc, char *argv[])
{
    // Showing result of work 'multiply' function
    printf("Result of multiplying 4 and 3 = %d\n", multiply(4, 3));
    printf("Result of multiplying 13 and 17 = %d\n", multiply(13, 17));

    return 0;
}