// The maximum sum subarray problem consists in finding the maximum sum of a
// contiguous subsequence in an array or list of integers:

// maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4});
// should be 6: {4, -1, 2, 1}

// Easy case is when the list is made up of only positive numbers and the maximum
// sum is the sum of the whole array. If the list is made up of only negative numbers, return 0 instead.

// Empty list is considered to have zero greatest sum. Note that the empty list
// or array is also a valid sublist/subarray.

#include <iostream>
#include <vector>
#include <numeric>

bool isArrNegative(const std::vector<int> &arr)
{
    for (const auto &el : arr)
    {
        if (el > 0)
            return false;
    }

    return true;
}

bool isArrPositive(const std::vector<int> &arr)
{
    for (const auto &el : arr)
    {
        if (el < 0)
            return false;
    }

    return true;
}

// Returns max subarray sum of contiguous elements in sequence
// Solves the "Maximum subarray problem" with the "Kadane's Algorithm"
int maxSequence(const std::vector<int> &arr)
{
    // If array consists only of negative numbers OR array is empty -> return 0
    if (isArrNegative(arr) || arr.empty())
        return 0;

    // If array consists only of positive numbers -> return their sum
    if (isArrPositive(arr))
        return std::accumulate(std::cbegin(arr), std::cend(arr), 0);

    int maxSoFar{*(std::cbegin(arr))}, maxEndingHere{0};

    for (const auto &el : arr)
    {
        maxEndingHere += el;

        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;

        if (maxEndingHere < 0)
            maxEndingHere = 0;
    }

    return maxSoFar;
}



int main()
{
    std::vector<int> vec;

    std::cout << maxSequence(vec) << std::endl;
    std::cout << maxSequence({-1, -2, -3, -4, -5}) << std::endl;
    std::cout << maxSequence({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << std::endl;
    std::cout << maxSequence({-2, 1, -3, 4, -1, 2, 1, -5}) << std::endl;

    return EXIT_SUCCESS;
}
