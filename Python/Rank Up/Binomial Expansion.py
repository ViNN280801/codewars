import re
import math


def axb_extract(expr):
    # Reversing the expression and splitting by '+' or '-'
    parts = expr[::-1].split('+', 1)
    if len(parts) != 2:
        parts = expr[::-1].split('-', 1)
        parts[0] += '-'

    # Extracting 'a', 'x', and 'b' values
    a_str = parts[1][1:][::-1] or '1'
    a = int(a_str) if a_str != '-' else -1
    x = parts[1][0]
    b = int(parts[0][::-1])

    return a, x, b


def binom_coef(n):
    coef = [1]
    for i in range(n):
        coef.append(coef[-1] * (n - i) // (i + 1))
    coef += coef[:-n % 2 or -1][::-1]
    return coef


def expand(expr):
    parts = expr.split('^', 1)
    exponent = int(parts[1])

    if exponent == 0:
        return '1'
    elif exponent == 1:
        return parts[0][1:-1]

    a, x, b = axb_extract(parts[0][1:-1])

    coef = binom_coef(exponent)

    qa = 1
    qb = 1
    for i in range(exponent+1):
        coef[exponent-i] *= qb
        coef[i] *= qa
        qb *= b
        qa *= a

    elements = []

    for i in range(exponent, -1, -1):
        sign = '+' if coef[i] > 0 else '-'
        elem_coef = abs(coef[i]) if abs(coef[i]) > 1 else ''
        if i > 1:
            elements.append('{}{}{}^{}'.format(sign, elem_coef, x, i))
        elif i == 1:
            elements.append('{}{}{}'.format(sign, elem_coef, x))
        else:
            elements.append('{}{}'.format(sign, elem_coef))

    if elements[0][0] == '+':
        elements[0] = elements[0][1:]

    if len(elements[-1]) == 1:
        elements[-1] += '1'

    return ''.join(elements)


P = re.compile(r'\((-?\d*)(\w)\+?(-?\d+)\)\^(\d+)')


def expand_smart(expr):
    a, v, b, e = P.findall(expr)[0]

    if e == '0':
        return '1'

    o = [int(a != '-' and a or a and '-1' or '1'), int(b)]
    e, p = int(e), o[:]

    for _ in range(e-1):
        p.append(0)
        p = [o[0] * coef + p[i-1]*o[1] for i, coef in enumerate(p)]

    res = '+'.join(f'{coef}{v}^{e-i}' if i != e else str(coef)
                   for i, coef in enumerate(p) if coef)

    return re.sub(r'\b1(?=[a-z])|\^1\b', '', res).replace('+-', '-')


print(expand("(2x+1)^0"), "1")
print(expand("(x+1)^0"), "1")
print(expand("(x+1)^1"), "x+1")
print(expand("(x+1)^2"), "x^2+2x+1")

print(expand("(x-1)^0"), "1")
print(expand("(x-1)^1"), "x-1")
print(expand("(x-1)^2"), "x^2-2x+1")

print(expand("(5m+3)^4"), "625m^4+1500m^3+1350m^2+540m+81")
print(expand("(2x-3)^3"), "8x^3-36x^2+54x-27")
print(expand("(7x-7)^0"), "1")

print(expand("(-5m+3)^4"), "625m^4-1500m^3+1350m^2-540m+81")
print(expand("(-2k-3)^3"), "-8k^3-36k^2-54k-27")
print(expand("(-7x-7)^0"), "1")
