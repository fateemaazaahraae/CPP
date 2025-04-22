# include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) { (void)other; }

RPN&    RPN::operator=(const RPN& other)
{
    (void)other;
    return *this;
}

const char* RPN::argException::what() const throw()
{
    return "Error: Wrong number of arguments";
}

const char* RPN::badArgumentException::what() const throw()
{
    return "Error: bad argument";
}

const char* RPN::devZeroException::what() const throw()
{
    return "Error: Cannot devide by Zero";
}

bool    RPN::isNumber(std::string input)
{
    if (input.find_first_not_of("0123456789") == std::string::npos && input.length() == 1)
        return true;
    return false;
}

bool    RPN::isOperator(std::string input)
{
    if (input.find_first_not_of("+-*/") == std::string::npos && input.length() == 1)
        return true;
    return false;
}

void RPN::reversePolishNotation(std::stack<int>& stack, std::string input)
{
    int a, b, result;

    if (RPN::isNumber(input))
        stack.push(atoi(input.c_str()));
    else if (RPN::isOperator(input))
    {
        switch (input[0])
        {
            case '+':
                if (stack.size() >= 2)
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    result = b + a;
                    stack.push(result);
                }
                else
                    throw badArgumentException();
                break;
            case '-':
                if (stack.size() >= 2)
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    result = b - a;
                    stack.push(result);
                }
                else
                    throw badArgumentException();
                break;
            case '*':
                if (stack.size() >= 2)
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    result = b * a;
                    stack.push(result);
                }
                else
                    throw badArgumentException();
                break;
            case '/':
                if (stack.size() >= 2)
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    if (a == 0)
                        throw devZeroException();
                    result = b / a;
                    stack.push(result);
                }
                else
                    throw badArgumentException();
                break;

            default:
                break;
        }
    }
    else
        throw badArgumentException();
}