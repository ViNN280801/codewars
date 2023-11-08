#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct Pair_t
{
    long long first;
    long long snd;
} Pair;

typedef struct count_divs_t
{
    long long *div_list;
    size_t size;
} count_divs;

void set_count_divs(count_divs *cd)
{
    cd->div_list = NULL;
    cd->size = 0ul;
}

int isSquare(long long num) { return (long long)sqrt(num) * (long long)sqrt(num) == num; }

count_divs getSquaredDivisors(long long num)
{
    size_t countOfDivisors = 0ul;
    for (long long i = 1ll; i <= num; ++i)
        if (num % i == 0)
            ++countOfDivisors;

    count_divs cd;
    set_count_divs(&cd);
    cd.size = countOfDivisors;

    long long *divisorsList = (long long *)calloc(countOfDivisors, sizeof(long long));
    if (!divisorsList)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        return cd;
    }

    size_t idx = 0ul;
    for (long long i = 1ll; i <= num; ++i)
        if (num % i == 0)
        {
            divisorsList[idx] = i * i;
            ++idx;
        }
    cd.div_list = divisorsList;
    return cd;
}

long long sumOfList(count_divs *cd)
{
    long long sum = 0ll;
    for (size_t i = 0ul; i < cd->size; ++i)
        sum += cd->div_list[i];
    return sum;
}

Pair **listSquared(long long m, long long n, int *length)
{
    if (n < m || m < 1 || n < 1)
        return NULL;

    Pair **result = NULL;
    size_t resultSize = 0ul;

    for (long long i = m; i <= n; ++i)
    {
        count_divs divs = getSquaredDivisors(i);
        long long sum = sumOfList(&divs);

        if (isSquare(sum))
        {
            ++resultSize;
            result = (Pair **)realloc(result, resultSize * sizeof(Pair *));
            if (!result)
            {
                fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }

            result[resultSize - 1] = (Pair *)malloc(sizeof(Pair));
            if (!result[resultSize - 1])
            {
                fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }

            result[resultSize - 1]->first = i;
            result[resultSize - 1]->snd = sum;
        }
    }

    *length = (int)resultSize;
    return result;
}

Pair **listSquaredSmart(long long m, long long n, int *length)
{
    Pair **result = calloc(0, sizeof(Pair *));
    int cnt = 0;
    for (long long i = m; i <= n; i++)
    {
        long long sum = 0;
        for (long long j = 1; j <= i; j++)
            if (i % j == 0)
                sum += j * j;
        double sqrt_sum = sqrt(sum);
        if ((long long)floor(sqrt_sum) == sqrt_sum)
        {
            Pair *pr = calloc(1, sizeof(Pair));
            pr->first = i;
            pr->snd = sum;
            result = (Pair **)realloc(result, (cnt + 1) * sizeof(Pair *));
            result[cnt++] = pr;
        }
    }
    *length = cnt;
    return result;
}

int main()
{
    int length = 0;
    Pair **result = listSquared(1, 250, &length);
    for (int i = 0; i < length; ++i)
        printf("%lld\t%lld\n", result[i]->first, result[i]->snd);
    free(result);

    result = listSquared(42, 250, &length);
    for (int i = 0; i < length; ++i)
        printf("%lld\t%lld\n", result[i]->first, result[i]->snd);
    free(result);

    return EXIT_SUCCESS;
}
