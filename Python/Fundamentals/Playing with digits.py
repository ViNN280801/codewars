def dig_pow(n, p):
    digits = list(str(n))
    result = i = 0
    for digit in digits:
        result += int(digit)**(p + i)
        i += 1

    if result % n == 0:
        return int(result / n)
    return -1


print(dig_pow(89, 1))
print(dig_pow(92, 1))
print(dig_pow(695, 2))
print(dig_pow(46288, 3))
print(dig_pow(46288, 5))
