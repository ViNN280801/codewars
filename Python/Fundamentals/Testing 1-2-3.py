def number(lines: list) -> list:
    for i, el in enumerate(lines):
        lines[i] = str(i + 1) + ': ' + el
    return lines


def number_smart(lines: list) -> list:
    return ['%d: %s' % v for v in enumerate(lines, 1)]


print(number(['a', 'b', 'c']))
print(number_smart(['a', 'b', 'c']))
