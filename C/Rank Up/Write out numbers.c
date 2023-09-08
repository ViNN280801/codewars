// Task: Create a function that transforms any positive number to a string
// representing the number in words. The function should work for all numbers between 0 and 999999.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>

#define BUFF_SIZE 256
#define ARR_SIZE(arr) sizeof(arr) / sizeof(*arr)

static const char *numbers_from_0_to_19[] = {"zero", "one", "two", "three", "four", "five",
                                             "six", "seven", "eight", "nine", "ten",
                                             "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                                             "sixteen", "seventeen", "eighteen", "nineteen"};
static const char *tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

/**
 * @brief Calculates count of digits in the number
 * @param n number
 * @return Count of digits in the number
 */
int get_count_of_digits_in_number(unsigned n) { return (unsigned)floor(log10((unsigned)(n)) + 1); }

/**
 * @brief Reversing number
 * @param pint array of integers to reverse them
 * @param size size of array 'pint'
 */
void reverse_pint(int *pint, int size)
{
    int temp = 0;
    for (int i = 0; i < size / 2; i++)
    {
        temp = pint[i];
        pint[i] = pint[size - i - 1];
        pint[size - i - 1] = temp;
    }
}

/**
 * @brief Splits specified number on digits. Uses 'reverse_pint()' function to return
 * digits of number in properly order (not reverse): properly: 1934 -> 1 9 3 4; reversed: 1934 -> 4 3 9 1
 * @param n number to split it into a digits
 * @param rev flag of reverse, if "false" returns digits in properly order, if "false" - in reversed order
 * @return Pointer to an array of integer, where elements are digits of number 'n'
 */
int *split_number_on_digits(int n, bool rev)
{
    int size = get_count_of_digits_in_number(n), i = 0;

    // Allocating memory for integer array
    int *digits = (int *)calloc(size, sizeof(int));

    // If memory not allocated properly -> exiting from the programm
    if (!digits)
    {
        fprintf(stderr, "Error: split_number_on_digits(%d, ...): Can't allocate memory. Exiting with failure status: %s\n",
                n, strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (n > 0)
    {
        digits[i] = n % 10;
        n /= 10;
        i++;
    }
    if (rev == false)
        reverse_pint(digits, size);
    return digits;
}

/**
 * @brief Converts numbers from 0 to 99 to string representation
 * @param n number
 * @return Number in string representation. Empty string ("") if smth wrong
 */
const char *numbers_from_0_to_99_to_str(unsigned short n)
{
    if (n > 99u)
        return "";

    if (n <= 19u)
        return numbers_from_0_to_19[n];

    if (n > 19u)
    {
        char *buf = (char *)calloc(BUFF_SIZE, sizeof(char));
        if (!buf)
        {
            fprintf(stderr, "Error: Can't allocate memory. Exiting with failure status: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        int *digits = split_number_on_digits(n, false);

        for (size_t i = 0ul; i < ARR_SIZE(tens); i++)
            if ((size_t)(digits[0] - 2) == i)
                strncat(buf, tens[i], strlen(tens[i]));

        for (size_t i = 0ul; i < ARR_SIZE(numbers_from_0_to_19) - 9ul; i++)
            if (digits[1] == 0)
                break;
            else if ((size_t)(digits[1]) == i)
            {
                strcat(buf, "-");
                strncat(buf, numbers_from_0_to_19[i], strlen(numbers_from_0_to_19[i]));
            }

        buf[strlen(buf) + 1ul] = 0x00;

        free(digits);
        digits = NULL;

        return buf;
    }

    return "";
}

/**
 * @brief Converts numbers from 100 to 999 to string representation
 * @param n number
 * @return Number in string representation. Empty string ("") if smth wrong
 */
const char *numbers_from_100_to_999_to_str(unsigned n)
{
    // Checking bounds
    if (n < 100u || n > 999u)
        return "";

    const char *tens = numbers_from_0_to_99_to_str(n % 100u),
               *hundreds = numbers_from_0_to_99_to_str(n / 100u);

    char *buf = (char *)calloc(BUFF_SIZE, sizeof(char));
    if (!buf)
    {
        fprintf(stderr, "Error: Can't allocate memory. Exiting with failure status: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    strncpy(buf, hundreds, strlen(hundreds));
    strcat(buf, " hundred");

    if (n % 100u == 0)
    {
        buf[strlen(buf) + 1ul] = 0x00;
        return buf;
    }

    strcat(buf, " ");
    strncat(buf, tens, strlen(tens));

    buf[strlen(buf) + 1ul] = 0x00;

    return buf;
}

/**
 * @brief Converts numbers from 0 to 999 to string representation
 * @param n number
 * @return Number in string representation. Empty string ("") if smth wrong
 */
const char *numbers_from_0_to_999_to_str(unsigned n)
{
    if (n <= 99u)
        return numbers_from_0_to_99_to_str(n);
    else if (n >= 100u && n <= 999u)
        return numbers_from_100_to_999_to_str(n);
    else
        return "";
}

/**
 * @brief Converts numbers from 1'000 to 999'999 to string representation
 * @param n number
 * @return Number in string representation. Empty string ("") if smth wrong
 */
const char *numbers_from_1000_to_999999_to_str(unsigned n)
{
    // Checking bounds
    if (n < 1000u || n > 999999u)
        return "";

    const char *hundreds = numbers_from_0_to_999_to_str(n % 1000u),
               *thousands = numbers_from_0_to_999_to_str(n / 1000u);

    char *buf = (char *)calloc(BUFF_SIZE, sizeof(char));
    if (!buf)
    {
        fprintf(stderr, "Error: Can't allocate memory. Exiting with failure status: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    strncpy(buf, thousands, strlen(thousands));
    strcat(buf, " thousand");

    if (n % 1000u == 0)
    {
        buf[strlen(buf) + 1ul] = 0x00;
        return buf;
    }

    strcat(buf, " ");
    strncat(buf, hundreds, strlen(hundreds));

    buf[strlen(buf) + 1ul] = 0x00;

    return buf;
}

/**
 * @brief Converts number to a string representaion: 1 -> one
 * @param n number to convert
 * @param buf pointer to a buffer that stores string representation of number 'n'
 * @return String representation of number 'n'
 */
char *number_to_words(unsigned n, char *buf)
{
    if (n <= 99u)
        sprintf(buf, "%s", numbers_from_0_to_99_to_str(n));
    else if (n >= 100u && n <= 999u)
        sprintf(buf, "%s", numbers_from_100_to_999_to_str(n));
    else if (n >= 1000u && n <= 999999u)
        sprintf(buf, "%s", numbers_from_1000_to_999999_to_str(n));
    else
        strcpy(buf, "\0");

    return buf;
}

/* === Smart way to solve it === */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *const names_0_19[] = {[0] = "", [1] = "one", [2] = "two", [3] = "three", [4] = "four", [5] = "five", [6] = "six", [7] = "seven", [8] = "eight", [9] = "nine", [10] = "ten", [11] = "eleven", [12] = "twelve", [13] = "thirteen", [14] = "fourteen", [15] = "fifteen", [16] = "sixteen", [17] = "seventeen", [18] = "eighteen", [19] = "nineteen"};
const char *const names_20_90[] = {[2] = "twenty", [3] = "thirty", [4] = "forty", [5] = "fifty", [6] = "sixty", [7] = "seventy", [8] = "eighty", [9] = "ninety"};

static char *compose(unsigned n, char *num_string)
{
    if (n >= 1000)
    {
        num_string = compose(n / 1000, num_string);
        return compose(n % 1000, num_string + sprintf(num_string, " %s%s", "thousand", (n % 1000) ? " " : ""));
    }
    else if (n >= 100)
    {
        num_string = compose(n / 100, num_string);
        return compose(n % 100, num_string + sprintf(num_string, " %s%s", "hundred", (n % 100) ? " " : ""));
    }
    else if (n >= 20)
        return compose(n % 10, num_string + sprintf(num_string, "%s%s", names_20_90[n / 10], (n % 10) ? "-" : ""));
    else
    {
        num_string += sprintf(num_string, "%s", names_0_19[n]);
        return num_string;
    }
}

char *number_to_words(unsigned n, char *num_string)
{
    if (n == 0)
        return strcpy(num_string, "zero");
    compose(n, num_string);
    return num_string;
}

/* ============================= */

int main()
{
    unsigned n = 0u;
    char *s = (char *)calloc(BUFF_SIZE, sizeof(char));
    if (!s)
    {
        fprintf(stderr, "Error: Can't allocate memory. Exiting with failure status: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (n != 9999999u)
    {
        scanf("%u", &n);
        s = number_to_words(n, s);
        printf("%s\n", s);
    }

    if (s)
        free(s);
    s = NULL;

    return 0;
}
