#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b3("Charlie", 10);
        Form f1("TopSecret", 30, 20);
        std::cout << b3 << std::endl;
        std::cout << f1 << std::endl;
        b3.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}