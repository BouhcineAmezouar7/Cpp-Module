#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default") {}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {}

// Copy assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        // target is const and cannot be assigned
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException();

    std::string filename = target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if (!outfile)
        throw ErrorCreatingFileException();

    outfile << "       _-_\n"
               "    /~~   ~~\\\n"
               " /~~         ~~\\\n"
               "{               }\n"
               " \\  _-     -_  /\n"
               "   ~  \\\\ //  ~\n"
               "_- -   | | _- _\n"
               "  _ -  | |   -_\n"
               "      // \\\\\n";
    outfile.close();
}
const char *ShrubberyCreationForm::ErrorCreatingFileException::what() const throw()
{
    return "Error creating the shrubbery file!";
}