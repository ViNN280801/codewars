#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#include <stddef.h>
#include <stdbool.h>

/**
 * @brief Checks if specified number is odd
 * @param num number
 * @return "true" if num is odd, otherwise "false"
 */
bool is_odd(int num) { return num % 2; }

/**
 * @brief Calculates count of even numbers in the array
 * @param a size of the array
 * @param arr array
 * @return Count of the even numbers in the array
 */
size_t count_of_even(size_t a, int const arr[a])
{
    // Counter for even numbers
    size_t count = 0ul;

    // If even - increment counter
    for (size_t i = 0ul; i < a; i++)
        if (!is_odd(arr[i]))
            count++;

    return count;
}

/**
 * @brief Copying to 'filtered' all even numbers
 * @param a size of the array
 * @param array array
 * @param filtered ptr on preallocated array
 * @param f ptr on size of the filtered array
 */
void get_even_numbers(size_t a, int const array[a], int *filtered, size_t *f)
{
    // If ptr points to void - break the fcn
    if (!filtered)
        return;

    // Get size of the filtered array
    size_t even_arr_size = count_of_even(a, array);
    *f = even_arr_size;

    // Copying all even elems to filtered array
    size_t j = 0ul;
    for (size_t i = 0ul; i < a; i++)
    {
        if (!is_odd(array[i]))
            filtered[j++] = array[i];
    }
}

void get_even_numbers_smart(size_t a, const int array[a], int *filtered, size_t *f)
{
    int j = 0;

    for (int i = 0; i < a; i++)
        if (array[i] % 2 == 0)
            filtered[j++] = array[i];

    *f = j;
}

int main()
{
    int *filtered = (int *)calloc(4ul, sizeof(int));
    if (!filtered)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    size_t f = 0ul;
    int const array[] = {2, 4, 5, 6, 8};

    get_even_numbers(sizeof(array) / sizeof(*array), array, filtered, &f);

    for (size_t i = 0ul; i < f; i++)
        printf("%d ", filtered[i]);
    printf("\n");

    free(filtered);
    filtered = NULL;

    return 0;
}
