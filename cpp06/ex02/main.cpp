#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

// Prototypes
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 5; i++)
    {
        Base* obj = generate();

        std::cout << "Identify by pointer: ";
        identify(obj);

        std::cout << "Identify by reference: ";
        identify(*obj);

        delete obj;
        std::cout << "----" << std::endl;
    }

    std::cout << "Testing unknown type identification:" << std::endl;

    Base* b = new Base();

    std::cout << "Identify by pointer: ";
    identify(b);

    std::cout << "Identify by reference: ";
    identify(*b);

    delete b;

    return 0;
}
