// Task Instructions:
// Given a mathematical expression as a string you must return the result as a number.

// Numbers:
// Number may be both whole numbers and/or decimal numbers. The same goes for the returned result.
// Operators

// You need to support the following mathematical operators:
// Multiplication *
// Division / (as floating point division)
// Addition +
// Subtraction -

// Operators are always evaluated from left-to-right, and * and / must be evaluated before + and -.

// Parentheses:
// You need to support multiple levels of nested parentheses, ex. (2 / (2 + 3.33) * 4) - -6

// Whitespace:
// There may or may not be whitespace between numbers and operators.
// An addition to this rule is that the minus sign (-) used for negating numbers
// and parentheses will never be separated by whitespace. I.e all of the following are valid expressions.

// 1-1    // 0
// 1 -1   // 0
// 1- 1   // 0
// 1 - 1  // 0
// 1- -1  // 2
// 1 - -1 // 2
// 1--1   // 2

// 6 + -(4)   // 2
// 6 + -( -4) // 10

// And the following are invalid expressions:
// 1 - - 1    // Invalid
// 1- - 1     // Invalid
// 6 + - (4)  // Invalid
// 6 + -(- 4) // Invalid

// Validation:
// You do not need to worry about validation - you will only receive
// valid mathematical expressions following the above rules.

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

// Simple lambda expr that defines if 'ch' symbol is mathematical operation sign
constexpr auto isMathSign{[](char const &ch)
                          { return ch == '*' || ch == '/' || ch == '+' || ch == '-'; }};

// Returns calculated number from two numbers and sign represented as "std::string"
std::string calcNum(double const &a, double const &b, char const &op)
{
    switch (op)
    {
    case '*':
        return std::to_string(a * b);
    case '/':
        return std::to_string(a / b);
    case '+':
        return std::to_string(a + b);
    case '-':
        return std::to_string(a - b);
    default:
        return "";
    }
}

// Returns calculated part of an expression
std::string calcGenericPart(std::string &expr, size_t const &posOfSign)
{
    char sign{expr.at(posOfSign)};
    bool isSndNumberNegative{false};
    size_t posOfLastDigInFstNum{posOfSign - 1UL}, posOfFirstDigInFstNum{posOfLastDigInFstNum},
        posOfFirstDigInSndNum{posOfSign + 1UL}, posOfLastDigInSndNum{posOfFirstDigInSndNum};

    // Defining first digit of the first number
    while (!isMathSign(expr.at(posOfFirstDigInFstNum)))
    {
        // Last iteration -> sign
        if (posOfFirstDigInFstNum != 0UL)
            posOfFirstDigInFstNum--;

        if (posOfFirstDigInFstNum == 0UL)
            break;
    }

    if (posOfFirstDigInFstNum != 0UL)
        posOfFirstDigInFstNum++;

    if (isMathSign(expr.at(posOfFirstDigInSndNum)))
    {
        posOfFirstDigInSndNum++;
        posOfLastDigInSndNum++;
        isSndNumberNegative = true;
    }

    // Defining last digit of the second number
    while (!isMathSign(expr.at(posOfLastDigInSndNum)))
    {
        // Last iteration -> sign
        posOfLastDigInSndNum++;
        if (posOfLastDigInSndNum == expr.length())
            break;
    }

    if (posOfLastDigInSndNum != expr.length())
        posOfLastDigInSndNum--;

    // Converting strings to the double numbers
    double fstNum{std::stod(expr.substr(posOfFirstDigInFstNum, posOfSign - posOfFirstDigInFstNum))},
        sndNum{std::stod(expr.substr(posOfFirstDigInSndNum,
                                     posOfLastDigInSndNum - posOfFirstDigInSndNum + 1UL))};

    if (isSndNumberNegative)
        sndNum *= -1.0;

    // Erasing old numbers and inserting new calculated number
    expr.erase(posOfFirstDigInFstNum, posOfLastDigInSndNum - posOfFirstDigInFstNum + 1UL);
    expr.insert(posOfFirstDigInFstNum, calcNum(fstNum, sndNum, sign));

    return expr;
}

// Returns calculated part of an expression in dependence of specified signs
// If bool flag 'signs' is "true" -> operations are "*" and "/"
// Otherwise - "+" and "-"
std::string calcSpecificPart(std::string &expr, size_t const &countOfSigns,
                             bool const &signs = true)
{
    char sign1{}, sign2{};

    // At first we calculate in order what is multiplied or divided, then the rest
    if (signs == true)
        sign1 = '*', sign2 = '/';
    else
        sign1 = '+', sign2 = '-';

    for (size_t i{}; i < countOfSigns; i++)
    {
        size_t posOfSign{};
        for (size_t j{}; j < expr.size(); j++)
        {
            if (expr.at(j) == sign1 || expr.at(j) == sign2)
            {
                posOfSign = j;

                if (posOfSign != 0UL)
                    break;
            }

            if (expr.find(sign1) == std::string::npos &&
                expr.find(sign2) == std::string::npos)
                break;
        }
        calcGenericPart(expr, posOfSign);
    }
    return expr;
}

// Modifies expression if expression has double signs
void replaceDoubleSignsInExpr(std::string &expr, std::string const &signs)
{
    size_t posOfDoubleSigns{expr.find(signs)};

    // While ".find()" do not return "std::string::npos" (max size of the string)
    while (posOfDoubleSigns != std::string::npos)
    {
        if (signs == "--" || signs == "++")
            expr.replace(expr.find(signs), 2UL, "+");
        else if (signs == "+-" || signs == "-+")
            expr.replace(expr.find(signs), 2UL, "-");

        // Updating position of signs
        posOfDoubleSigns = expr.find(signs);
    }
}

// Returns calculated expression from the one expression
std::string calcWholeExpression(std::string const &expr)
{
    // Initializing copy of the initial expression to erasing unnecessary symbols
    std::string exprCopy{expr};

    // Counting multiplication and divion sings
    auto countOfMultDiv{std::count_if(std::cbegin(exprCopy), std::cend(exprCopy),
                                      [](char const &sign)
                                      {
                                          return sign == '*' || sign == '/';
                                      })};

    // We need to calculate the expression count of signs times
    // so, we have count of the multiplication and division signs
    // which we would calculate at first in the order which they
    // are located in the expression, then - calculate the rest of
    // add and subtracting operations
    calcSpecificPart(exprCopy, static_cast<size_t>(countOfMultDiv));

    // Getting rid of unnecessary repetitive characters
    replaceDoubleSignsInExpr(exprCopy, "--");
    replaceDoubleSignsInExpr(exprCopy, "-+");
    replaceDoubleSignsInExpr(exprCopy, "+-");
    replaceDoubleSignsInExpr(exprCopy, "++");

    // Counting adding and subtracting sings
    auto countAddSubtr{std::count_if(std::cbegin(exprCopy), std::cend(exprCopy),
                                     [](char const &sign)
                                     {
                                         return sign == '+' || sign == '-';
                                     })};

    // Sign of negative number doesn't count
    if (exprCopy.find('+') == 0UL || exprCopy.find('-') == 0UL)
        countAddSubtr--;

    calcSpecificPart(exprCopy, static_cast<size_t>(countAddSubtr), false);

    return exprCopy;
}

double calc(std::string expr)
{
    // If we got an empty string - return nil as a result
    if (expr.empty() || expr == " ")
        return 0.0;

    // Removing all whitespaces from the expression
    expr.erase(std::remove_if(std::begin(expr), std::end(expr), [](char const &ch)
                              { return ch == ' '; }),
               std::cend(expr));

    // Finding position of brackets
    size_t posOflbracket{expr.find_last_of('(')}, posOfrbracket{expr.find_first_of(')')};

    // If there is no more brackets
    while (posOflbracket != std::string::npos && posOfrbracket != std::string::npos)
    {
        // Updating positions for the next calculations
        posOflbracket = expr.find_last_of('(');
        posOfrbracket = expr.find_first_of(')');

        if (posOflbracket == std::string::npos && posOfrbracket == std::string::npos)
            break;

        std::string exprInParentheses{expr.substr(posOflbracket + 1UL,
                                                  posOfrbracket - posOflbracket - 1UL)};

        // Erasing expression in parentheses
        expr.erase(posOflbracket, exprInParentheses.length() + 2UL);

        // Replacing erased expression in parentheses with a calculation result
        expr.insert(posOflbracket, calcWholeExpression(exprInParentheses));
    }

    // If expression doesn't have a parentheses - just calculate whole expression
    if (posOflbracket == std::string::npos && posOfrbracket == std::string::npos)
    {
        std::string calculated{calcWholeExpression(expr)};

        // Erasing all symbols in the expression
        expr.clear();

        // Replacing erased expression in parentheses with a calculation result
        expr.insert(0UL, calculated);
    }
    return std::stold(expr);
}

int main()
{
    std::cout << calc("150.000000-450") << std::endl;
    std::cout << calc("150.000000450") << std::endl;
    std::cout << calc("-1.335000-150.000000-450") << std::endl;
    std::cout << calc("2+1.665000-5-600.000000/4-450") << std::endl;
    std::cout << calc("(2 / (2 + 3.33 / 4 * 2 - 5 - 6 * 100 / 4 - 450) * 4) - -6") << std::endl;
    std::cout << calc("1 + 1") << std::endl;
    std::cout << calc("2 + 3.33 / 4 * 2 - 5 - 6 * 100 / 4 - 450") << std::endl;
    std::cout << calc("100") << std::endl;
    std::cout << calc("2 + 2 * 2") << std::endl;
    std::cout << calc("2 + 2 / 2 * 2") << std::endl;
    std::cout << calc("(2 / (2 + 3.33) * 4) - -6") << std::endl;
    std::cout << calc("(           (2/-   601.335000)*4)+6") << std::endl;
    std::cout << calc("-0.013304+6") << std::endl;
    std::cout << calc("8/16") << std::endl;
    std::cout << calc("3 -(-1)") << std::endl;
    std::cout << calc("2 + -2") << std::endl;
    std::cout << calc("10- 2- -5") << std::endl;
    std::cout << calc("(((10)))") << std::endl;
    std::cout << calc("3 * 5") << std::endl;
    std::cout << calc("-7 * -(6 / 3)") << std::endl;
    std::cout << calc("-1") << std::endl;
    std::cout << calc("-(-1)") << std::endl;
    std::cout << calc("-(-(1))") << std::endl;
    std::cout << calc("10 * 24 * -24 * 36 * -2 + -37 / -89 * 83") << std::endl;
    std::cout << calc("-72 - -21 / 94 - -85 / -2 / -31 * -64 - -30") << std::endl;
    std::cout << calc("") << std::endl;
    std::cout << calc(" ") << std::endl;
    std::cout << calc("0") << std::endl;
    std::cout << calc(" 0 ") << std::endl;
    std::cout << calc("-16 / -42 / -42 - -94 - 12 + 76 / -89 * -100") << std::endl;
    std::cout << calc("77 / 83 / 82 * -7 * -10 - 38 - -35 - 37") << std::endl;
    std::cout << calc("-(-(-1))") << std::endl;

    return EXIT_SUCCESS;
}

// Tests:
/*
Expected: equal to 195.394 (+/- 1e-06) -> Actual: 195.394
Expected: equal to -225224 (+/- 1e-06) -> Actual: -225224
Expected: equal to 410.416 (+/- 1e-06) -> Actual: 410.416
Expected: equal to 307.194 (+/- 1e-06) -> Actual: 307.194
Expected: equal to -6682.63 (+/- 1e-06) -> Actual: -6682.63
Expected: equal to 222.811 (+/- 1e-06) -> Actual: 222.811
Expected: equal to -128.996 (+/- 1e-06) -> Actual: -128.996
Expected: equal to 56.8048 (+/- 1e-06) -> Actual: 56.8048
Expected: equal to 109.772 (+/- 1e-06) -> Actual: 109.771
Expected: equal to -5762.62 (+/- 1e-06) -> Actual: -5762.62
*/
