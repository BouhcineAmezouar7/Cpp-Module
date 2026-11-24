#ifndef RPN_HPP
#define RPN_HPP

// * Includes
#include <iostream>
#include <algorithm>
#include <stack>

// * Functions
void rpnCalculation(std::stack<int> &stack, char sign);
void rpnParsing(std::string rpn);

#endif
