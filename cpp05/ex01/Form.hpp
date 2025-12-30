#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration
class Form
{
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int executeGrade;

public:
    Form();                                                         // default constructor
    Form(const std::string &name, int signGrade, int executeGrade); // parameterized constructor
    Form(const Form &other);                                        // copy constructor
    Form &operator=(const Form &other);                             // copy assignment operator
    ~Form();                                                        // destructor

    const std::string &getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat &bureaucrat);

    // Exception classes
    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };
    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);
