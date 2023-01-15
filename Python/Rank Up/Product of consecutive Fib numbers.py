# Task: The Fibonacci numbers are the numbers in the following integer sequence (Fn):
# 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...
# such as
# F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1.
# Given a number, say prod (for product), we search two Fibonacci numbers F(n) and F(n+1) verifying

# F(n) * F(n+1) = prod.

# Your function productFib takes an integer (prod) and returns an array:
# [F(n), F(n+1), true] or {F(n), F(n+1), 1} or (F(n), F(n+1), True)
# depending on the language if F(n) * F(n+1) = prod.
# If you don't find two consecutive F(n) verifying F(n) * F(n+1) = prodyou will return
# [F(n), F(n+1), false] or {F(n), F(n+1), 0} or (F(n), F(n+1), False)
# F(n) being the smallest one such as F(n) * F(n+1) > prod.

# Some Examples of Return:
# (depend on the language)
# productFib(714) # should return (21, 34, true),
#                 # since F(8) = 21, F(9) = 34 and 714 = 21 * 34
# productFib(800) # should return (34, 55, false),
#                 # since F(8) = 21, F(9) = 34, F(10) = 55 and 21 * 34 < 800 < 34 * 55
# -----
# productFib(714) # should return [21, 34, true],
# productFib(800) # should return [34, 55, false],
# -----
# productFib(714) # should return {21, 34, 1},
# productFib(800) # should return {34, 55, 0},
# -----
# productFib(714) # should return {21, 34, true},
# productFib(800) # should return {34, 55, false},

# Note:
# You can see examples for your language in "Sample Tests".

def Fibonacci_seq(n):
    ''' Returns number from Fibonacci sequence in 'n' range '''
    # Initializing two first numbers from Fibonacci sequence
    num_1, num_2 = 0, 1

    # Using 'for' loop to reassign (swaping) numbers
    for i in range(n - 1):
        num_1, num_2 = num_2, num_1 + num_2

    # Returning number from Fibonacci sequence
    return num_1


def productFib(prod):
    ''' Returns two numbers from fibonacci sequence and True if product of these numbers equals passed value, False - otherwise'''

    # Handling exceptional case:
    if prod == 0:
        return [0, 1, True]

    # Initializing current value fro future checking
    current_value = 0
    # Count of sequence
    count = 0
    # Numbers from sequence
    num_1 = num_2 = 0

    # While current value less than product (passed value)
    while current_value < prod:
        # While less -> increasing count of sequence
        count += 1
        # Taking numbers from Fibonacci sequence
        # 1st number - previous number from Fibonacci sequence
        num_1 = Fibonacci_seq(count)
        # 1st number - next number from Fibonacci sequence
        num_2 = Fibonacci_seq(count + 1)
        # Current value is product of these two numbers from Fibonacci sequence
        current_value = num_1 * num_2

    # In any case we need to return these two consecutive numbers from Fibonacci sequence in list type

    # If this current value (product of two consecutive numbers from Fibonacci sequence) equals passed value ('prod') -> return True last parameter
    if current_value == prod:
        return [num_1, num_2, True]

    # Else return False last parameter
    return [num_1, num_2, False]


# Checking results
print('Checking results of my function: ')
print(productFib(714))
print(productFib(800))
print(productFib(4895))
print(productFib(5895))
print(productFib(0))

# Clever solution


def clever_productFib(prod):
    ''' Returns two numbers from fibonacci sequence and True if product of these numbers equals passed value, False - otherwise'''
    a, b = 0, 1
    while prod > a * b:
        a, b = b, a + b
    return [a, b, prod == a * b]


# Checking results of clever function
print('\nChecking results of clever function: ')
print(clever_productFib(714))
print(clever_productFib(800))
print(clever_productFib(4895))
print(clever_productFib(5895))
print(clever_productFib(0))
