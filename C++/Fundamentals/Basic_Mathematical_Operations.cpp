// Task: Your task is to create a function that does four basic mathematical operations.

// The function should take three arguments - operation(string/char), value1(number), value2(number).
// The function should return result of numbers after applying the chosen operation.
// Examples(Operator, value1, value2) --> output

// ('+', 4, 7) --> 11
// ('-', 15, 18) --> -3
// ('*', 5, 5) --> 25
// ('/', 49, 7) --> 7

#include <iostream>
#include <functional>

using basic_op_func = std::function<int(char, int, int)>;

// Returns basic mathematical operation result.
// Returns -1 if operation 'op' is invalid (is not the '+', '-', '*' or '/')
int basicOp(char op, int val1, int val2)
{
    switch (op)
    {
    case '+':
        return val1 + val2;
    case '-':
        return val1 - val2;
    case '*':
        return val1 * val2;
    case '/':
        return (val2 != 0) ? (val1 / val2) : -1;
    default:
        return -1;
    }
}

int main()
{
    basic_op_func func{basicOp};

    std::cout << func('+', 5, 4) << std::endl;
    std::cout << func('-', 11, 8) << std::endl;
    std::cout << func('*', 3, 4) << std::endl;
    std::cout << func('/', 16, 4) << std::endl;
    std::cout << func('/', 16, 0) << std::endl;

    return EXIT_SUCCESS;
}
