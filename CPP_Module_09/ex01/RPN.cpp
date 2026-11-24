#include "RPN.hpp"

void rpnCalculation(std::stack<int> &stack, char sign)
{
    int first = 0;
    int second = 0;
    int result = 0;

    // * check if there are at least 2 numbers in the stack, if not, then the expression is invalid
    //   and throw an error
    if (stack.size() < 2)
        throw std::runtime_error("Error: Not enough numbers in the expression");

    // * get the first and second numbers from the stack
    first = stack.top(); // get
    stack.pop();         // remove

    second = stack.top();
    stack.pop();

    // calculate the result (but we need to change the order of fisrt and second number because when we get the top of stack that is the last number)
    if (sign == '+')
        result = second + first;
    else if (sign == '-')
        result = second - first;
    else if (sign == '*')
        result = second * first;
    else if (sign == '/')
    {
        if (first == 0)
            throw std::runtime_error("Error: Division by zero");
        result = second / first;
    }

    // * push the result back to the stack
    stack.push(result);
}

void rpnParsing(std::string rpn)
{
    std::stack<int> stack;

    for (size_t i = 0; i < rpn.length(); i++)
    {
        // Skip whitespace
        while (rpn[i] && rpn[i] <= 32 && rpn[i] >= 0)
            i++;

        // check string if empty
        if (!rpn[i])
            break;

        // store the number in the stack and if the character is an operator, perform the calculation
        if (std::isdigit(rpn[i]))
        {
            // * check if next char is not number because we need handle only (0-9)
            if (std::isdigit(rpn[i + 1]))
                throw std::runtime_error("Error: (0-9) only allowed");
            // * convert char to int and push it to the stack
            // * like '3' - '0' = 51 - 48 = 3
            stack.push(rpn[i] - '0'); 
        }
        else if (rpn[i] == '+')
        {
            rpnCalculation(stack, '+');
        }
        else if (rpn[i] == '-')
        {
            rpnCalculation(stack, '-');
        }
        else if (rpn[i] == '*')
        {
            rpnCalculation(stack, '*');
        }
        else if (rpn[i] == '/')
        {
            rpnCalculation(stack, '/');
        }
        else
            throw std::runtime_error("Error: Invalid character in expression");
    }

    // * check if there are more than 1 number in the stack, if yes, then the expression is invalid
    if (stack.size() > 1)
        throw std::runtime_error("Error: Too many numbers in the expression");

    // * if the stack is empty, then the expression is invalid
    if (stack.empty())
        throw std::runtime_error("Error: Empty expression");
    else
        std::cout << stack.top() << std::endl;
}
