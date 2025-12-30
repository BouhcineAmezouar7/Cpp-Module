#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm; // Forward declaration
class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat(); //default constructor
    Bureaucrat(const std::string& name, int grade); //parameterized constructor
    Bureaucrat(const Bureaucrat& other); //copy constructor
    Bureaucrat& operator=(const Bureaucrat& other); //copy assignment operator
    ~Bureaucrat(); //destructor

    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    // Exception classes
    class GradeTooLowException : public std::exception
    {
        const char* what() const throw();
    };
    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };
    void signForm(AForm &form) const;
    void executeForm(const AForm &form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);