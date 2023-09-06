#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

/**
 * @brief Struct that represents two integer values
 * which are represents first and last values from the interval
 * where the second value is not taken into account: [first, second)
 */
struct interval
{
    int first;
    int second;
};

/**
 * @brief Comparator function for "qsort()"
 * @param a ptr on a 1st interval
 * @param b ptr on a 2nd interval
 * @return Result of the comparison
 */
int compareIntervals(void const *a, void const *b)
{
    const struct interval *interval_a = (const struct interval *)a;
    const struct interval *interval_b = (const struct interval *)b;

    return interval_a->first - interval_b->first;
}

/**
 * @brief Calculates a common length of the all specified intervals
 * @param v array of intervals
 * @param n count of the intervals
 * @return Common length of the all intervals. -1 if smth wrong
 */
int sum_intervals(const struct interval *v, size_t n)
{
    // Check if pointer 'v' points to the void, and that 'n' is not null
    if (!v || n == 0ul)
        return -1;

    // Sort the intervals by their start values
    // This is essential for merging overlapping intervals
    struct interval *sorted_intervals = (struct interval *)calloc(n, sizeof(struct interval));
    if (!sorted_intervals)
    {
        fprintf(stderr, "Can't allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Copying all elements to sort them
    for (size_t i = 0ul; i < n; i++)
        sorted_intervals[i] = v[i];

    // Sort the intervals based on their first values
    qsort(sorted_intervals, n, sizeof(struct interval), compareIntervals);

    // Initialize variables for tracking the merged intervals
    int merged_first = sorted_intervals[0].first,
        merged_second = sorted_intervals[0].second,
        length = 0;

    // Merge overlapping intervals and calculate the total length
    for (size_t i = 1ul; i < n; i++)
    {
        if (sorted_intervals[i].first <= merged_second)
        {
            // Overlapping intervals, merge them
            if (sorted_intervals[i].second > merged_second)
                merged_second = sorted_intervals[i].second;
        }
        else
        {
            // Non-overlapping interval, add the length to the total
            length += merged_second - merged_first;
            merged_first = sorted_intervals[i].first;
            merged_second = sorted_intervals[i].second;
        }
    }

    // Add the length of the last merged interval
    length += merged_second - merged_first;

    // Free the memory allocated for sorted intervals and zeroing out the ptr
    free(sorted_intervals);
    sorted_intervals = NULL;

    return length;
}

int main()
{
    struct interval intervals[] = {{1, 4}, {7, 10}, {3, 5}};
    size_t num_intervals = sizeof(intervals) / sizeof(intervals[0]);

    printf("Result = %d\n", sum_intervals(intervals, num_intervals));

    return 0;
}
