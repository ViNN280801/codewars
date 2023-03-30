def nb_dig(n, d):
    if not (n >= 0 and d >= 0 and d <= 9):
        return -1
    lst = []
    for i in range(0, n + 1):
        lst.insert(i, i ** 2)
    count = 0
    for el in lst:
        count += list(str(el)).count(str(d))
    return count


def nb_dig_clever(n, d):
    return sum(str(i*i).count(str(d)) for i in range(n+1))


print(nb_dig(10, 1))
print(nb_dig(25, 1))

print(nb_dig_clever(10, 1))
print(nb_dig_clever(25, 1))
