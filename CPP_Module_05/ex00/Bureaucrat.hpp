#pragma once

#include <iostream>

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    // orthodox canonical form
    Bureaucrat();                                   // default constructor
    Bureaucrat(const std::string &name, int grade); // parameterized constructor
    Bureaucrat(const Bureaucrat &other);            // copy constructor
    Bureaucrat &operator=(const Bureaucrat &other); // copy assignment operator
    ~Bureaucrat();                                  // destructor

    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    // Exception classes
    class GradeTooLowException : public std::exception
    {
        const char *what() const throw(); // override method what()
    };
    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);