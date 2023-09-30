def race(v1: int, v2: int, g: int) -> list:
    if v1 >= v2:
        return None
    t = 3600 * g / (v2 - v1)
    return [int(x) for x in [t / 3600, t / 60 % 60, t % 60]]
