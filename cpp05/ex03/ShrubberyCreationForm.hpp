#pragma once

#include <iostream>

#include "AForm.hpp"
#include <fstream>
class AForm;

class ShrubberyCreationForm : public AForm
{
private:
    const std::string target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();
    void execute(const Bureaucrat &executor) const;
    class ErrorCreatingFileException : public std::exception
    {
        virtual const char *what() const throw();
    };
};
