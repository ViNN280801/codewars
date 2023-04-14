#include <stdio.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>

void remove_every_other(size_t *length, int array[*length])
{
    int *pint = (int *)calloc(*length, sizeof(*array));
    if (!pint)
    {
        printf("Error while allocating memory! Exiting with \'-1\' status");
        exit(-1);
    }

    size_t initSize = *length, currentSize = 0;
    for (size_t i = 0; i < initSize; i++)
    {
        if (i % 2 == 0)
        {
            pint[currentSize] = array[i];
            currentSize++;
        }
        else
            (*length)--;
    }

    for (size_t i = 0; i < currentSize; i++)
        array[i] = pint[i];

    for (size_t i = 0; i < currentSize; i++)
        printf("%d\t", array[i]);
    printf("\n");
}

void remove_every_other_clever(size_t *length, int array[*length])
{
    size_t j = 0;
    for (size_t i = 0; i < *length; i++)
        if (i % 2 == 0)
            array[j++] = array[i];
    *length = j;
}

int main()
{
    size_t len = 10;
    int parr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    remove_every_other(&len, parr);

    len = 3;
    int parr2[] = {1, 2, 3};
    remove_every_other(&len, parr2);

    return 0;
}
