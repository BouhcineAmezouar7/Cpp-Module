#include "Form.hpp"

// Default constructor
Form::Form() : name("Default"), isSigned(false), signGrade(150), executeGrade(150) {}

// Parameterized constructor
Form::Form(const std::string &name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

// Copy constructor
Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade) {}

// Copy assignment operator
Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
        // name, signGrade, and executeGrade are const and cannot be assigned
    }
    return *this;
}

// Destructor
Form::~Form() {}

const std::string &Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getSignGrade() const
{
    return signGrade;
}

int Form::getExecuteGrade() const
{
    return executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}