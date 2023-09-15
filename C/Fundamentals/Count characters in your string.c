#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define COUNTS_SIZE 128

//  assign char counts to the provided pre-allocated array
//  pre-existing values in array aren't guaranteed to be 0
//  from test string: "aaa", counts['a'] should be == to 3

void count(const char *string, unsigned counts[COUNTS_SIZE])
{
    for (int i = 0; i < COUNTS_SIZE; i++)
        counts[i] = 0;

    for (size_t i = 0ul; i < strlen(string); i++)
        counts[(unsigned char)string[i]]++;
}

void count_another(const char *string, unsigned counts[COUNTS_SIZE])
{

    for (int i = 0; i < COUNTS_SIZE; i++)
        counts[i] = 0;

    for (; *string; *string++)
        counts[*string]++;
}

void count_another_2(const char *string, unsigned counts[COUNTS_SIZE])
{

    for (int i = 0; i < COUNTS_SIZE; i++)
        counts[i] = 0;

    for (; *string; *string++)
        counts[*string]++;
}

int main()
{
    unsigned counts[COUNTS_SIZE];
    count("This is the string to sort", counts);

    for (int i = 0; i < COUNTS_SIZE; i++)
        if (counts[i] > 0)
            printf("Character %c: %u\n", (char)i, counts[i]);

    return 0;
}
