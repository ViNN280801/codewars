#include <stdlib.h>

long long *tribonacci(const long long signature[3], size_t n)
{
    // Checking bounds
    if (n == 0ul)
        return NULL;

    // Allocating memory
    long long *seq = (long long *)calloc(n, sizeof(long long));
    if (!seq)
        return NULL;

    // Copying elements from 'signature' to 'seq'
    for (size_t i = 0ul; i < 3ul; i++)
        seq[i] = signature[i];

    // Calculating sequence
    for (size_t i = 3ul; i < n; i++)
        seq[i] = seq[i - 1] + seq[i - 2] + seq[i - 3];

    return seq;
}

int main()
{
    return 0;
}
