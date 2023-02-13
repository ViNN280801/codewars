#include <stack>
#include <string>
#include <vector>

static const std::vector operators = {'+', '-', '*', '/', '^'};
static const std::vector precedence = {1, 1, 2, 2, 3};

int getPrecedence(const char &ch)
{
    for (size_t i{0UL}; i < operators.size(); i++)
    {
        if (ch == operators[i])
            return precedence[i];
    }
    return -1;
}

std::string to_postfix(const std::string &expr)
{
    std::stack<char> stack;
    std::string result;

    for (char ch : expr)
    {
        if (isdigit(ch))
            result += ch;
        else if (ch == '(')
            stack.push(ch);
        else if (ch == ')')
        {
            while (!stack.empty() && stack.top() != '(')
            {
                result += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else
        {
            while (!stack.empty() && getPrecedence(stack.top()) >= getPrecedence(ch))
            {
                result += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.empty())
    {
        result += stack.top();
        stack.pop();
    }

    return result;
}