#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(20);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        // * The shortest span is 2 (between 9 and 11) and the longest span is 14 (between 3 and 17) */
        // 3 6 9 11 17
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
