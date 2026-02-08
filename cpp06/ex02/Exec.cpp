#include "Base.hpp"


Base *generate(void)
{
    int r = std::rand() % 3;
    switch (r)
    {
    case 0:
        std::cout << "Generate A" << std::endl;
        return (new A);
    case 1:
        std::cout << "Generate B" << std::endl;
        return (new B);
    default:
        std::cout << "Generate C" << std::endl;
        return (new C);
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p)) // check if p can be casted to A*
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknow type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception &bc)
    {
        try
        {
            (void)dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        }
        catch (std::exception &bc)
        {
            try
            {
                (void)dynamic_cast<C &>(p);
                std::cout << "C" << std::endl;
            }
            catch (std::exception &bc)
            {
                std::cout << "Unknow type" << std::endl;
            }
        }
    }
}