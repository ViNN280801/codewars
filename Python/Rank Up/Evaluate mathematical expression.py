# def isMathSign(symbol: str) -> bool:
#     """ Returns True if 'symbol' is a math sign. Otherwise - returns False """
#     if symbol == '*' or symbol == '/' or symbol == '+' or symbol == '-':
#         return True
#     return False


# def calcSimplestExpr(a: float, b: float, sign: str) -> float:
#     """ Returns calculated expression in relation to specified math sign. If 'sign' is unknown - returns None """
#     if sign == '*':
#         return a * b
#     elif sign == '/':
#         return a / b
#     elif sign == '+':
#         return a + b
#     elif sign == '-':
#         return a - b
#     else:
#         return None


# def replaceAllDoubleSigns(expr: str) -> str:
#     """ Replaces all double signs in the math expression """
#     return expr.replace(
#         '+-', '-').replace('-+', '-').replace('++', '+').replace('--', '+')


# def calcGenericPart(expr: str, posOfSign: int) -> str:
#     """ Performs calculation of simplest expression with modifying passed string,
#     i.e. previous expression erasing and replaced with result of the calculation """

#     sign = expr[posOfSign]
#     isSndNumIsNeg = False

#     posOfLastDigInFstNum = posOfSign - 1
#     posOfFirstDigInFstNum = posOfLastDigInFstNum
#     posOfFirstDigInSndNum = posOfSign + 1
#     posOfLastDigInSndNum = posOfFirstDigInSndNum

#     # Defining first digit of the first number
#     while not isMathSign(expr[posOfFirstDigInFstNum]):
#         # Last iteration -> sign
#         if posOfFirstDigInFstNum != 0:
#             posOfFirstDigInFstNum -= 1

#         if (expr[posOfFirstDigInFstNum] == 'e'):
#             posOfFirstDigInFstNum += 1

#         if posOfFirstDigInFstNum == 0 or posOfFirstDigInFstNum < 0:
#             break

#     if posOfFirstDigInFstNum != 0:
#         posOfFirstDigInFstNum += 1

#     if isMathSign(expr[posOfFirstDigInSndNum]):
#         posOfFirstDigInSndNum += 1
#         posOfLastDigInSndNum += 1
#         isSndNumIsNeg = True

#     # Defining last digit in the second number
#     while not isMathSign(expr[posOfLastDigInSndNum]):
#         # Last iteration -> sign
#         posOfLastDigInSndNum += 1

#         if posOfLastDigInSndNum == len(expr):
#             break

#         if (expr[posOfLastDigInSndNum] == 'e'):
#             posOfLastDigInSndNum += 2

#     if posOfLastDigInSndNum != len(expr):
#         posOfLastDigInSndNum -= 1

#     fstNum = float(expr[posOfFirstDigInFstNum:posOfLastDigInFstNum + 1])
#     sndNum = float(expr[posOfFirstDigInSndNum:posOfLastDigInSndNum + 1])

#     if isSndNumIsNeg:
#         sndNum *= -1

#     # Replacing old numbers from the string and inserting new calculated number
#     expr = expr.replace(expr[posOfFirstDigInFstNum:posOfLastDigInSndNum + 1],
#                         str(calcSimplestExpr(fstNum, sndNum, sign)))

#     # Getting rid of unnecessary repetitive characters
#     expr = replaceAllDoubleSigns(expr)

#     return expr


# def calcSpecificPart(expr: str, countOfSigns: int, signs: bool = True) -> str:
#     """ Returns calculated part of an expression in dependence of specified signs
#         If bool flag 'signs' is "true" -> operations are "*" and "/"
#         Otherwise - "+" and "-" """

#     sign1 = str()
#     sign2 = str()

#     # At first we calculate in order what is multiplied or divided, then the rest
#     if signs == True:
#         sign1 = '*'
#         sign2 = '/'
#     else:
#         sign1 = '+'
#         sign2 = '-'

#     i = int()
#     while (i < countOfSigns):
#         posOfSign = int()
#         for j, ch in enumerate(expr):
#             if expr[j] == sign1 or expr[j] == sign2:
#                 posOfSign = j

#                 if posOfSign != 0:
#                     break
#         expr = calcGenericPart(expr, posOfSign)
#         i += 1

#     return expr


# def calcWholeExpression(expr: str) -> str:
#     """ Returns calculated expression from the one expression """
#     # Initializing copy of the initial expression to erasing unnecessary symbols
#     exprCopy = expr

#     # Counting multiplication and divion sings
#     countOfMultDiv = sum(1 for x in expr if x == '*' or x == '/')

#     # We need to calculate the expression count of signs times
#     # so, we have count of the multiplication and division signs
#     # which we would calculate at first in the order which they
#     # are located in the expression, then - calculate the rest of
#     # add and subtracting operations
#     exprCopy = calcSpecificPart(exprCopy, countOfMultDiv)

#     # Getting rid of unnecessary repetitive characters
#     expr = replaceAllDoubleSigns(expr)

#     # Counting adding and subtracting sings
#     countOfAddSubtr = sum(1 for x in exprCopy if x == '+' or x == '-')

#     if exprCopy.find('+') == 0 or exprCopy.find('-') == 0:
#         countOfAddSubtr -= 1

#     if exprCopy.find('E+') != -1 or exprCopy.find('e+') != -1 or exprCopy.find('E-') != -1 or exprCopy.find('e-') != -1:
#         countOfAddSubtr -= 1

#     exprCopy = calcSpecificPart(exprCopy, countOfAddSubtr, False)

#     return exprCopy


# def calc(expr: str) -> float:
#     """ Calculates expression from the string representation """

#     # If we got an empty string - return nil as a result
#     if expr == '' or expr == ' ':
#         return 0.0

#     # At first, removing all whitespaces from the string and replacing all double signs
#     expr = expr.replace(' ', '')
#     expr = replaceAllDoubleSigns(expr)

#     # Finding position of brackets
#     posOflbracket = expr.rfind('(')
#     posOfrbracket = expr.find(')')

#     # If there is no more brackets
#     while posOflbracket != -1 and posOfrbracket != -1:
#         # Updating positions for the next calculations
#         posOflbracket = expr.rfind('(')
#         posOfrbracket = expr.find(')')

#         if posOflbracket == -1 and posOfrbracket == -1:
#             break

#         exprInParentheses = expr[posOflbracket + 1:posOfrbracket]

#         # Erasing expression in parentheses
#         expr = expr.replace('(' + exprInParentheses + ')', '')
#         # Replacing erased expression in parentheses with a calculation result
#         expr = expr[:posOflbracket] + \
#             calcWholeExpression(exprInParentheses) + expr[posOflbracket:]
#         # Getting rid of unnecessary repetitive characters
#         expr = replaceAllDoubleSigns(expr)

#     # If expression doesn't have a parentheses - just calculate whole expression
#     if posOflbracket == -1 and posOfrbracket == -1:
#         calculated = calcWholeExpression(expr)

#         # Replacing expression in parentheses with a calculation result
#         expr = calculated

#     return float(expr)


# print(calc('1 + 1'))
# print(calc('8/16'))
# print(calc('3 -(-1)'))
# print(calc('2 + -2'))
# print(calc('10- 2- -5'))
# print(calc('(((10)))'))
# print(calc('3 * 5'))
# print(calc('-7 * -(6 / 3)'))
# print(calc('61 / -9 / -17 * -3 - 40 * -73 - 23 * -12'))
# print(calc('-34 + 45 - 5 * -73 * -28 - 79 - -28 - 31'))
# print(calc('-71 - -76 - -19 + -84 / 42 / -96 / -66 / 99'))
# print(calc('19-3.1884501581471274e-06'))


### BELOW IS PRESENTED NOT MY SOLUTION !!! ###
### MY SOLUTION IS ABOVE - ALL COMMENTED CODE ###
### BUT IT CALLS TIME LIMIT (more than 12s) ###
import re
from operator import mul, truediv as div, add, sub


OPS = {'*': mul, '/': div, '-': sub, '+': add}


def calc(expression):
    tokens = re.findall(r'[.\d]+|[()+*/-]', expression)
    return parse_AddSub(tokens, 0)[0]


def parse_AddSub(tokens, iTok):

    v, iTok = parse_MulDiv(tokens, iTok)

    while iTok < len(tokens) and tokens[iTok] != ')':
        tok = tokens[iTok]
        if tok in '-+':
            v2, iTok = parse_MulDiv(tokens, iTok+1)
            v = OPS[tok](v, v2)

    return v, iTok


def parse_MulDiv(tokens, iTok):

    v, iTok = parse_Term(tokens, iTok)

    while iTok < len(tokens) and tokens[iTok] in '*/':
        op = tokens[iTok]
        v2, iTok = parse_Term(tokens, iTok+1)
        v = OPS[op](v, v2)

    return v, iTok


def parse_Term(tokens, iTok):
    tok = tokens[iTok]

    if tok == '(':
        v, iTok = parse_AddSub(tokens, iTok+1)
        if iTok < len(tokens) and tokens[iTok] != ')':
            raise Exception()

    elif tok == '-':
        v, iTok = parse_Term(tokens, iTok+1)
        v, iTok = -v, iTok-1

    else:
        v = float(tok)

    return v, iTok+1
