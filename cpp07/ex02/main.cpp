#include <iostream>
#include "Array.hpp"

int main()
{
    std::cout << "==== TEST 1: Default constructor ====" << std::endl;
    Array<int> a;
    std::cout << "Size: " << a.size() << std::endl;

    std::cout << "\n==== TEST 2: Size constructor ====" << std::endl;
    Array<int> b(5);
    for (unsigned int i = 0; i < b.size(); i++)
        b[i] = i * 10;

    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;

    std::cout << "\n==== TEST 3: Copy constructor ====" << std::endl;
    Array<int> c(b);
    c[0] = 999;

    std::cout << "Original b[0]: " << b[0] << std::endl;
    std::cout << "Copied   c[0]: " << c[0] << std::endl;

    std::cout << "\n==== TEST 4: Assignment operator ====" << std::endl;
    Array<int> d;
    d = b;
    d[1] = 888;

    std::cout << "Original b[1]: " << b[1] << std::endl;
    std::cout << "Assigned d[1]: " << d[1] << std::endl;

    std::cout << "\n==== TEST 5: Exception (out of bounds) ====" << std::endl;
    try
    {
        std::cout << b[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 6: Const Array ====" << std::endl;
    const Array<int> e(b);
    std::cout << "e[2] = " << e[2] << std::endl;

    std::cout << "\n==== TEST 7: Different type (string) ====" << std::endl;
    Array<std::string> s(3);
    s[0] = "Hello";
    s[1] = "CPP";
    s[2] = "Templates";

    for (unsigned int i = 0; i < s.size(); i++)
        std::cout << s[i] << std::endl;

    std::cout << "\n==== ALL TESTS DONE ====" << std::endl;
    return 0;
}
