import math


def is_prime(num: int) -> bool:
    """ Returns True if 'num' is prime. Otherwise - False """
    if num <= 1:
        return False

    i = 2
    while i <= int(math.sqrt(num)):
        if num % i == 0:
            return False
        i += 1
    return True


print(is_prime(5), is_prime(4483), is_prime(3164),
      is_prime(7789), is_prime(1), is_prime(0))
