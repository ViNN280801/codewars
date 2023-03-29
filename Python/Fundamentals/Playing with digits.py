def dig_pow(n, p):
    digits = list(str(n))
    result = i = 0
    for digit in digits:
        result += int(digit)**(p + i)
        i += 1

    if result % n == 0:
        return int(result / n)
    return -1


def dig_pow_clever(n, p):
    s = 0
    for i, c in enumerate(str(n)):
        s += pow(int(c), p+i)
    return s/n if s % n == 0 else -1


print(dig_pow(89, 1))
print(dig_pow(92, 1))
print(dig_pow(695, 2))
print(dig_pow(46288, 3))
print(dig_pow(46288, 5))

print()
print(dig_pow_clever(89, 1))
print(dig_pow_clever(92, 1))
print(dig_pow_clever(695, 2))
print(dig_pow_clever(46288, 3))
print(dig_pow_clever(46288, 5))
