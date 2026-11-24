#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
    unsigned int max_size;
    std::vector<int> vec;
    std::vector<int>::iterator it;

public:
    Span(); // * Default constructor
    Span(unsigned int N); // * Parameterized constructor
    Span(const Span &other); // * Copy constructor
    Span &operator=(const Span &other); // * Copy assignment operator
    ~Span(); // * Destructor

    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
};