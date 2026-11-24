#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm *rrf;

        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 150);

        std::cout << "--- Creating and executing forms ---" << std::endl;
        std::cout << "------------------------------------------------------------------------" << std::endl;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        b1.signForm(*rrf);
        b1.executeForm(*rrf);
        delete rrf;

        std::cout << "------------------------------------------------------------------------" << std::endl;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
        std::cout << *rrf << std::endl;
        b2.signForm(*rrf);
        b2.executeForm(*rrf);
        delete rrf;

        std::cout << "------------------------------------------------------------------------" << std::endl;
        rrf = someRandomIntern.makeForm("presidential pardon", "Marvin");
        std::cout << *rrf << std::endl;
        b1.signForm(*rrf);
        b1.executeForm(*rrf);
        delete rrf;

        std::cout << "------------------------------------------------------------------------" << std::endl;
        // Attempt to create an unknown form
        rrf = someRandomIntern.makeForm("unknown form", "Target");
        delete rrf; // In case it doesn't throw, avoid memory leak
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}