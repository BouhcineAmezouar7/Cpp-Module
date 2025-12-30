#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
#include <cstdlib>

class Bureaucrat; // Forward declaration
class AForm
{
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int executeGrade;

public:
    AForm();                                                         // default constructor
    AForm(const std::string &name, int signGrade, int executeGrade); // parameterized constructor
    AForm(const AForm &other);                                       // copy constructor
    AForm &operator=(const AForm &other);                            // copy assignment operator
    virtual ~AForm();                                                // destructor

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
    class FormNotSignedException : public std::exception
    {
        const char *what() const throw();
    };

    virtual void execute(const Bureaucrat &executor) const = 0; // pure virtual function
};

std::ostream &operator<<(std::ostream &os, const AForm &form);
