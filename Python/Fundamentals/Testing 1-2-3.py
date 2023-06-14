def number(lines: list) -> list:
    for i, el in enumerate(lines):
        lines[i] = str(i + 1) + ': ' + el
    return lines


print(number(['a', 'b', 'c']))
