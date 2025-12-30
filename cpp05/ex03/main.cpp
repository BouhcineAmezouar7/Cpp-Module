#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    {
        Intern someRandomIntern;
        Bureaucrat bob("Bob", 80);
        AForm *form = someRandomIntern.makeForm("robotomy request", "Bob");

        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }

    std::cout << "------------------------------------------------------------------------" << std::endl;
    {
        Intern someRandomIntern;
        Bureaucrat alice("Alice", 16);
        AForm *form = someRandomIntern.makeForm("presidential pardon", "Alice");

        alice.signForm(*form);
        alice.executeForm(*form);
        delete form;
    }
    std::cout << "------------------------------------------------------------------------" << std::endl;

    {
        Intern someRandomIntern;
        Bureaucrat charlie("Charlie", 138);
        AForm *form = someRandomIntern.makeForm("shrubbery creation", "Home");

        charlie.signForm(*form);
        charlie.executeForm(*form);
        delete form;
    }
    return 0;
}