import numpy as np


def fib_negative(n: int) -> int:
    """
    Calculate the Fibonacci number for negative indices using an iterative approach.

    Parameters:
    - n: The negative index for which the Fibonacci number needs to be calculated (type: int)

    Returns:
    - The Fibonacci number at the specified negative index (type: int)
    """
    # Check if the input index is less than or equal to 0
    assert n <= 0

    # Base cases: Fibonacci numbers for -1 and 0
    if n == 0:
        return 0
    if n == -1:
        return 1

    # Initialize variables for the Fibonacci sequence
    prev_num = 0
    next_num = 1

    # Calculate Fibonacci number iteratively for negative indices
    num = prev_num - next_num
    for i in range(n, -2):
        prev_num, next_num = next_num, num
        num = prev_num - next_num
    return num


def fib_positive(n: int) -> int:
    """
    Calculate the Fibonacci number for positive indices using an iterative approach.

    Parameters:
    - n: The positive index for which the Fibonacci number needs to be calculated (type: int)

    Returns:
    - The Fibonacci number at the specified positive index (type: int)
    """
    # Check if the input index is greater than or equal to 0
    assert n >= 0

    # Base cases: Fibonacci numbers for 0, 1, and 2
    if n == 0:
        return 0
    if n == 1 or n == 2:
        return 1

    # Initialize variables for the Fibonacci sequence
    prev_num = 1
    next_num = 1

    # Calculate Fibonacci number iteratively for positive indices
    num = prev_num + next_num
    for i in range(3, n):
        prev_num, next_num = next_num, num
        num = prev_num + next_num
    return num


### My incorrect implementation (works too slow) ###
def fib_slow(n: int) -> int:
    """
    Calculates the nth Fibonacci number.

    Parameters:
    - n: The index for which the Fibonacci number needs to be calculated (type: int)

    Returns:
    - The Fibonacci number at the specified index (type: int)
    """
    # Check if the input index is less than or equal to 0
    if n <= 0:
        return fib_negative(n)
    else:
        return fib_positive(n)


def fib_helper(cur_num: int, next_num: int, koef_p: int, koef_q: int, count: int) -> int:
    """
    Calculate the Fibonacci number using an optimized matrix exponentiation method.

    Parameters:
    - cur_num: Current Fibonacci number in the sequence (type: int)
    - next_num: Next Fibonacci number in the sequence (type: int)
    - koef_p, koef_q: Coefficients for matrix exponentiation (type: int)
    - count: The remaining count of Fibonacci numbers to calculate (type: int)

    Returns:
    - The Fibonacci number at the specified index (type: int)
    """
    # Base case: if count is 0, return the current value of next_num
    if count == 0:
        return next_num

    # If count is even, use matrix exponentiation with updated coefficients
    if count % 2 == 0:
        new_current = koef_p ** 2 + koef_q ** 2
        new_next = koef_q ** 2 + 2 * koef_p * koef_q
        return fib_helper(cur_num, next_num, new_current, new_next, count / 2)
    else:
        # If count is odd, apply a different matrix exponentiation formula
        new_current = next_num * koef_q + cur_num * koef_q + cur_num * koef_p
        new_next = next_num * koef_p + cur_num * koef_q
        return fib_helper(new_current, new_next, koef_p, koef_q, count - 1)


def fib_slow_2(n: int) -> int:
    """
    Calculates the nth Fibonacci number using an optimized matrix exponentiation method for positive indices
    and an iterative approach for negative indices.

    Parameters:
    - n: The index for which the Fibonacci number needs to be calculated (type: int)

    Returns:
    - The Fibonacci number at the specified index (type: int)
    """
    # Check if the input index is greater than or equal to 0
    if n >= 0:
        return fib_helper(1, 0, 0, 1, n)
    # If the input index is negative, use an iterative approach
    if n < 0:
        cur_num, next_num = 0, 1
        # Calculate Fibonacci number iteratively for negative indices
        for _ in range(0, n, -1):
            cur_num, next_num = next_num - cur_num, cur_num
        return cur_num


### Correct fast implementation ###
def fib(n):
    if n == 0:
        return 0
    if n == -1 or n == 1 or n == 2:
        return 1

    if n < 2 and n > -2:
        return n
    negative = False
    if n < 0:
        negative = True
        n = abs(n)

    A = np.matrix([[0, 1], [1, 1]], dtype=object)
    Ap = pow(A, n-1)
    result = Ap * np.matrix([[0], [1]])
    if negative and (abs(n)+1) % 2 != 0:
        return -int(result[1])
    else:
        return int(result[1])


print(fib_slow(6))
print(fib_slow(-6))
print(fib_slow(-9))
print(fib_slow(9))
print(fib_slow(-8))
print(fib_slow(8))
print(fib_slow(-100))
print(fib_slow(-101))
print(fib_slow(-11))


print()
print(fib(-1))
print(fib(6))
print(fib(-6))
print(fib(-9))
print(fib(9))
print(fib(-8))
print(fib(8))
print(fib(-100))
print(fib(-101))
print(fib(-11))
