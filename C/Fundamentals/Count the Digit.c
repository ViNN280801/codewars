#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

#define BUFF_SIZE 1024

// Returns "true" if memory for char
// array was allocated correctly
// Otherwise returns "false" (other types is similar)
bool is_alloc_pchar(const char *__p)
{
    return (!__p) ? false : true;
}

// Allocates memory for char array with cheking on correctness
// Exiting with status '-1' if can't allocate memory (other types is similar)
char *alloc_mem_pchar(const size_t __arr_size)
{
    char *p = (char *)calloc(__arr_size, sizeof(char));

    if (!is_alloc_pchar(p))
    {
        printf("Can't allocate memory for array of characters. Exiting with \'-1\' status\n");
        exit(-1);
    }

    return p;
}

// Deallocating memory of char pointer (other types is similar)
void dealloc_mem_pchar(char *__p)
{
    free(__p);
    __p = NULL;
}

// Returns char array from integer value
char *int_to_pchar(int num)
{
    if (num == 0)
        return "0";

    size_t size = (size_t)(log10((double)(num))) + 1UL;
    char *pChar = alloc_mem_pchar(size);
    for (int i = size - 1; i >= 0; i--, num /= 10)
    {
        pChar[i] = (num % 10) + '0';
    }
    return pChar;
}

int nbDig(int n, int d)
{
    char *pChar = alloc_mem_pchar(BUFF_SIZE);
    for (int i = 0; i <= n; i++)
    {
        strcat(pChar, int_to_pchar(pow(i, 2)));
    }

    int counter = 0;
    for (size_t i = 0; i < strlen(pChar); i++)
    {
        if (d + '0' == pChar[i])
            counter++;
    }
    // Following line may occur problem of double free (in tests on the website codewars.com)
    // dealloc_mem_pchar(pChar);
    return counter;
}

int nbDig_clever(int n, int d)
{
    int count = (d == 0) ? 1 : 0;

    for (int k = 1; k <= n; k++)
    {
        int kk = k * k;
        while (kk != 0)
        {
            if (kk % 10 == d)
                count++;
            kk /= 10;
        }
    }

    return count;
}

int main()
{
    printf("%d\n", nbDig(10, 1));
    printf("%d\n", nbDig(25, 1));
    printf("%d\n", nbDig(5750, 0));

    printf("%d\n", nbDig_clever(10, 1));
    printf("%d\n", nbDig_clever(25, 1));
    printf("%d\n", nbDig_clever(5750, 0));

    return 0;
}
