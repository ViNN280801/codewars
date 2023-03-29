#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <stdbool.h>

// Returns "true" if memory for int
// array was allocated correctly
// Otherwise returns "false" (other types is similar)
bool is_alloc_pint(const int *__p)
{
    return (!__p) ? false : true;
}

// Allocates memory for integer array with cheking on correctness
// Exiting with status '-1' if can't allocate memory (other types is similar)
int *alloc_mem_pint(const size_t __arr_size)
{
    int *p = (int *)calloc(__arr_size, sizeof(int));

    if (!is_alloc_pint(p))
    {
        printf("Can't allocate memory for array of integers. Exiting with \'-1\' status\n");
        exit(-1);
    }

    return p;
}

// Returns count of digits in number
int get_count_of_digits_in_number(int num)
{
    int size = 0;
    while (num > 0)
    {
        num /= 10;
        size++;
    }
    return size;
}

// Prints array on terminal (other types is similar)
void print_pint(const int *__parr, const size_t __arr_size)
{
    printf("\n==== ==== ==== ==== ====\nArray:\n");
    for (size_t i = 0UL; i < __arr_size; i++)
    {
        printf("arr[%ld] = %d\n", i, __parr[i]);
    }
    printf("==== ==== ==== ==== ====\n\n");
}

// Returns int array (in descending order) that contains digits of a number
int *split_number_on_digits(int num)
{
    int size = get_count_of_digits_in_number(num), i = 0;
    int *digits = alloc_mem_pint(size);

    while (num > 0)
    {
        digits[i] = num % 10;
        num /= 10;
        i++;
    }
    return digits;
}

// Reversing number
void reverse_pint(int *pint, const int size)
{
    int temp = 0;
    for (int i = 0; i < size / 2; i++)
    {
        temp = pint[i];
        pint[i] = pint[size - i - 1];
        pint[size - i - 1] = temp;
    }
}

int digPow(int n, int p)
{
    int *digits = split_number_on_digits(n);
    int size = get_count_of_digits_in_number(n);
    reverse_pint(digits, size);

    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result += pow((double)(digits[i]), (double)(p + i));
    }

    return result % n == 0 ? result / n : -1;
}

int digPowClever(int n, int p)
{
    int numDigits = floor(log10(n)) + 1, result = 0, num = n;
    for (int i = p + numDigits - 1; i >= p; i--)
    {
        result += pow(num % 10, i);
        num /= 10;
    }
    if (result % n == 0)
        return result / n;
    return -1;
}

int main()
{
    printf("%d\n", digPow(89, 1));
    printf("%d\n", digPow(92, 1));
    printf("%d\n", digPow(695, 2));
    printf("%d\n", digPow(46288, 3));
    printf("%d\n", digPow(46288, 5));

    printf("\n%d\n", digPowClever(89, 1));
    printf("%d\n", digPowClever(92, 1));
    printf("%d\n", digPowClever(695, 2));
    printf("%d\n", digPowClever(46288, 3));
    printf("%d\n", digPowClever(46288, 5));

    return 0;
}
