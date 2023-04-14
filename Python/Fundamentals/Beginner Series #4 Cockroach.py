import math


def cockroach_speed(s: float) -> int:
    """ Returns speed in cm/s where is input is km/h """
    return math.floor(s * 100000 / 3600)


def cockroach_speed_clever(s: float) -> int:
    """ Returns speed in cm/s where is input is km/h """
    return s // 0.036


print(cockroach_speed(1.08))
print(cockroach_speed_clever(1.08))
