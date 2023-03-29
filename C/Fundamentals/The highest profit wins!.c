#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARR_SIZE(arr) (sizeof arr / sizeof arr[0])

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

void min_max(const int arr[], int count, int *min, int *max)
{
    *min = *max = arr[0];
    for (int i = 0; i < count; i++)
    {
        if (arr[i] < *min)
            *min = arr[i];

        if (arr[i] > *max)
            *max = arr[i];
    }

    printf("Min = %d\tMax = %d\n", *min, *max);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}, *min = alloc_mem_pint(1), *max = alloc_mem_pint(1);
    min_max(arr, ARR_SIZE(arr), min, max);

    return 0;
}
