#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int *race(int v1, int v2, int g)
{
    int *res = (int *)calloc(3ul, sizeof(int));
    if (!res)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    res[0] = res[1] = res[2] = -1;

    if (v1 < v2)
    {
        int t = 3600 * g / (v2 - v1);
        res[0] = t / 3600;
        res[1] = t / 60 % 60;
        res[2] = t % 60;
    }

    return res;
}