def two_sum(numbers: list, target) -> list:
    """ Returns two numbers that gives in a sum 'target' number """
    for i, num1 in enumerate(numbers):
        for j, num2 in enumerate(numbers):
            if num1 + num2 == target and i != j:
                return [i, j]
    return []


print(two_sum([1, 2, 3], 4))
print(two_sum([1234, 5678, 9012], 14690))
print(two_sum([2, 2, 3], 4))
