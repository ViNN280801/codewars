def sum_of_intervals(intervals) -> int:
    """
    Calculates total length of interval array, handling overlaps.

    Args: 
        intervals (list of list [pairs]) - A list of intervals, where each interval is represented as a list [min, max).

    Returns:
        int: Total length of specified intervals
    """

    # Sorting intervals
    intervals.sort()

    # Total length of intervals and boundary variable
    length = 0
    bound = intervals[0][0]

    # Iterating by each interval
    for interval in intervals:
        # If the current bound less then the end of the current interval
        if bound < interval[1]:
            # Adding length to variable
            length += interval[1] - max(bound, interval[0])

            # Updataing boundary variable
            bound = interval[1]

    return length


def sum_of_intervals_smart(intervals):
    s, top = 0, float("-inf")
    for a, b in sorted(intervals):
        if top < a:
            top = a
        if top < b:
            s, top = s+b-top, b
    return s


print(sum_of_intervals([(1, 5), (6, 10)]))
print(sum_of_intervals_smart([(1, 5), (6, 10)]))
