def count_by(x, n):
    """
    Returns a sequence of numbers counting by `x` `n` times.
    """
    return [(i + 1) * x for i in range(n)]

print(count_by(1, 10))
print(count_by(2, 5))
print(count_by(100, 5))
