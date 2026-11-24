#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    int i = 0;
    std::string formTypes[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

    while (i < 3)
    {
        if (formName.compare(formTypes[i]) == 0)
            break;
        i++;
    }

    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << formName << std::endl;
        return new PresidentialPardonForm(target);
    case 1:
        std::cout << "Intern creates " << formName << std::endl;
        return new RobotomyRequestForm(target);
    case 2:
        std::cout << "Intern creates " << formName << std::endl;
        return new ShrubberyCreationForm(target);
    default:
        std::cout << "Intern could not find the form: " << formName << std::endl;
        return NULL;
    }
}