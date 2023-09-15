from collections import Counter


def count(s: str):
    m = dict()

    for ch in s:
        if ch in m:
            m[ch] += 1
        else:
            m[ch] = 1

    return m


def count_smart(s: str):
    return Counter(s)
