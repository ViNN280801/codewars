#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using interval = std::pair<int, int>;
using intervals = std::vector<interval>;

/**
 * @brief Calculates a common length of the all specified intervals
 * @param intervals array of intervals
 * @return Common length of the all intervals. -1 if smth wrong
 */
int calculateIntervalsLength(std::vector<std::pair<int, int>> intervals)
{
    // Sorting intervals in ascending order
    std::sort(std::begin(intervals), std::end(intervals));

    // Calculating total length while maintaining a boundary variable to keep track
    // of the last processed final value
    // Desc of a lambda: Handles overlapping intervals
    return std::accumulate(intervals.begin(), intervals.end(), 0,
                           [bound = intervals[0].first](int sum, const auto &p) mutable
                           { 
                                if (bound < p.second) 
                                { 
                                    sum += (p.second - std::max(bound, p.first));
                                    bound = p.second; 
                                } 
                            return sum; });
}

/**
 * @brief Calculates a common length of the all specified intervals
 * @param __intervals array of intervals
 * @return Common length of the all intervals. -1 if smth wrong
 */
int sum_intervals(intervals __intervals)
{
    // If intervals is empty return -1
    if (__intervals.empty())
        return -1;

    // Sorting intervals in ascending order by first value
    std::set<interval> sortedIntervals(__intervals.cbegin(), __intervals.cend());

    // Initialize variables for tracking the merged intervals
    int mergedFirst{sortedIntervals.begin()->first},
        mergedSecond{sortedIntervals.begin()->second},
        len{};

    // Merge overlapping intervals and calculate the total length
    for (auto const &kv : sortedIntervals)
    {
        // Merge the overlapping interval
        if (kv.first <= mergedSecond)
        {
            if (kv.second > mergedSecond)
                mergedSecond = kv.second;
        }
        // If there is no overlapping interval - add to 'len' it length
        else
        {
            len += (mergedSecond - mergedFirst);
            mergedFirst = kv.first;
            mergedSecond = kv.second;
        }
    }

    // Adding length of the last merged interval
    len += (mergedSecond - mergedFirst);

    return len;
}

int main()
{
    std::cout << sum_intervals({{1, 4}, {7, 10}, {3, 5}}) << '\n';

    std::cout << calculateIntervalsLength({{1, 4}, {7, 10}, {3, 5}}) << '\n';

    return EXIT_SUCCESS;
}
