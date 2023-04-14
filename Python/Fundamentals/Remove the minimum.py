def remove_smallest(numbers: list) -> list:
    nums = list()

    idxOfSmallest = 0
    for i, num in enumerate(numbers):
        for j, num in enumerate(numbers):
            if numbers[idxOfSmallest] > num:
                idxOfSmallest = j
                break

    for i, num in enumerate(numbers):
        if i != idxOfSmallest:
            nums.append(num)

    return nums


print(remove_smallest([1, 2, 3, 4, 5]))
print(remove_smallest([1, 2, 3, 1, 1]))
print(remove_smallest([5, 3, 2, 1, 4]))
