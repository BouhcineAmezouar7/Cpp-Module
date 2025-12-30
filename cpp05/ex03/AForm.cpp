#include "AForm.hpp"

// Default constructor
AForm::AForm() : name("Default"), isSigned(false), signGrade(150), executeGrade(150) {}

// Parameterized constructor
AForm::AForm(const std::string &name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade) {}

// Copy assignment operator
AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
        // name, signGrade, and executeGrade are const and cannot be assigned
    }
    return *this;
}

// Destructor
AForm::~AForm() {}

const std::string &AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getSignGrade() const
{
    return signGrade;
}

int AForm::getExecuteGrade() const
{
    return executeGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low!";
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "AForm is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "AForm Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}