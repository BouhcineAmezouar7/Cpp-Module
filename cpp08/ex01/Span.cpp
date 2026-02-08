#include "Span.hpp"
#include <limits>

Span::Span() : max_size(0) {} // * Default constructor

Span::Span(unsigned int N) : max_size(N) {} // * Parameterized constructor

Span::Span(const Span &other) : max_size(other.max_size), vec(other.vec) {} // * Copy constructor

Span &Span::operator=(const Span &other) // * Copy assignment operator
{
    if (this != &other)
    {
        max_size = other.max_size;
        vec = other.vec;
    }
    return *this;
}

Span::~Span() {} // * Destructor

void Span::addNumber(int num)
{
    if (vec.size() >= max_size)
    {
        throw std::runtime_error("Span is already full");
    }
    vec.push_back(num);
}

int Span::shortestSpan()
{
    if (vec.size() == 0 || vec.size() == 1)
        throw std::runtime_error("no span can found");

    std::sort(vec.begin(), vec.end()); // * Sort the vector to find the shortest span easily

    int span;
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (i == 0)
            span = abs(vec[i] - vec[i + 1]); // * Initialize span with the first two elements
        for (size_t j = i + 1; j < vec.size(); j++)
        {
            if (span > abs(vec[i] - vec[j]))
                span = abs(vec[i] - vec[j]);
        }
    }
    return span;
}

int Span::longestSpan()
{
    if (vec.size() == 0 || vec.size() == 1)
        throw std::runtime_error("no span can found");

    std::sort(vec.begin(), vec.end());

    int span;
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (i == 0)
            span = abs(vec[i] - vec[i + 1]);
        for (size_t j = i + 1; j < vec.size(); j++)
        {
            if (span < abs(vec[i] - vec[j]))
                span = abs(vec[i] - vec[j]);
        }
    }
    return span;
}