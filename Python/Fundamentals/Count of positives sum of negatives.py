def count_positives_sum_negatives(arr):
    if len(arr) == 0:
        return []
    return [sum(1 for item in arr if item > 0), sum(item for item in arr if item < 0)]


print(count_positives_sum_negatives(
    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15]))
