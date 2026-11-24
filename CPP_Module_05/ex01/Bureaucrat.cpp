#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

// Copy assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
        // name is const and cannot be assigned
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    ++grade;
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

void Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.beSigned(*this); // *this to pass the current Bureaucrat object
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
