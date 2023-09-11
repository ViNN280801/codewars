import itertools


def permutations(s: str) -> list:
    s = ''.join(sorted(s))
    return list(set(''.join(perm) for perm in itertools.permutations(s)))
