#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Default") {}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target) {}

// Copy assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        // target is const and cannot be assigned
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}