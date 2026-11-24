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
    if (vec.size() < 2)
        throw std::runtime_error("no span can found");

    std::vector<int> sorted_vec = vec;
    std::sort(sorted_vec.begin(), sorted_vec.end()); // * Sort

    int span = sorted_vec[1] - sorted_vec[0]; // * Initialize span with the difference of the first two elements
    for (size_t i = 1; i < sorted_vec.size() - 1; i++)
    {
        int diff = sorted_vec[i + 1] - sorted_vec[i];
        if (diff < span)
            span = diff;
    }
    return span;
}

int Span::longestSpan()
{
    if (vec.size() < 2)
        throw std::runtime_error("no span can found");

    std::vector<int> sorted_vec = vec;
    std::sort(sorted_vec.begin(), sorted_vec.end());

    return sorted_vec[sorted_vec.size() - 1] - sorted_vec[0];
}