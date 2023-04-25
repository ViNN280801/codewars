#include <stdio.h>

#define LOOP(iter, size) for (unsigned iter = 0; iter < size; iter++)

/// @brief Searches indexes of the numbers in 'numbers' vector that gives in a sum 'target' number
/// @param count size of the 'numbers' array
/// @param numbers array of numbers
/// @param target target number which will be received by the sum of two numbers from 'numbers' vector
void twoSum(unsigned count, const int numbers[count], int target,
            unsigned *index1, unsigned *index2)
{
    LOOP(i, count)
    LOOP(j, count)
    if ((numbers[i] + numbers[j] == target) && (i != j))
    {
        *index1 = i;
        *index2 = j;
        return;
    }
}

void twoSum_clever(unsigned count, const int numbers[count], int target, unsigned *index1, unsigned *index2)
{
    for (*index1 = 0; *index1 < count; ++*index1)
        for (*index2 = *index1 + 1; *index2 < count; ++*index2)
            if (numbers[*index1] + numbers[*index2] == target)
                return;
}

int main()
{
    return 0;
}
