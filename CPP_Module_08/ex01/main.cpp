#include "Span.hpp"

int main()
{
    try
    {
        // work
        Span sp = Span(20);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;

        // error
        Span sp2 = Span(5);
        sp2.addNumber(1);
        std::cout << "shortestSpan: " << sp2.shortestSpan() << std::endl;
        
        Span sp3 = Span(1);
        sp3.addNumber(1);
        sp3.addNumber(2);


    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
