#include <stdio.h>
#include <stddef.h>

void count_positives_sum_negatives(int *values, size_t count, int *positivesCount, int *negativesSum)
{
    for (size_t i = 0UL; i < count; i++)
    {
        *positivesCount = (values[i] > 0) ? *positivesCount + 1 : *positivesCount;
        *negativesSum += (values[i] < 0) ? (values[i]) : 0;
    }
}

int main()
{
    return 0;
}
