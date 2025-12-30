#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{

    try
    {
        Bureaucrat bob("Bob", 30);
        ShrubberyCreationForm shrubberyForm("Home");
        RobotomyRequestForm robotomyForm("Alice");
        PresidentialPardonForm pardonForm("Charlie");
        bob.signForm(shrubberyForm);
        bob.executeForm(shrubberyForm);
        std::cout << "----------------------------------------" << std::endl;
        bob.signForm(robotomyForm);
        bob.executeForm(robotomyForm);
        std::cout << "----------------------------------------" << std::endl;
        bob.signForm(pardonForm);
        bob.executeForm(pardonForm);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}