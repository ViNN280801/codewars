def name_shuffler(str_: str):
    l = str_.split()
    l.reverse()
    return ' '.join(l)


def name_shuffler_smart(str_: str):
    return ' '.join(str_.split()[::-1])


print(name_shuffler('john McClane'))
print(name_shuffler_smart('john McClane'))
