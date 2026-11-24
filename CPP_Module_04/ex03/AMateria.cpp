#include "AMateria.hpp"

AMateria::AMateria() {
    this->type = "default";
    std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type) {
    std::cout << "AMateria Parameterized constructor called for " << type << std::endl;
}

AMateria::AMateria(AMateria const &other) : type(other.type) {
    std::cout << "AMateria Copy constructor called for " << type << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "AMateria Copy assignment operator called for " << type << std::endl;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria Destructor called for " << type << std::endl;
}

std::string const &AMateria::getType() const
{
    return this->type;
}

// Default implementation of use 
void AMateria::use(ICharacter &target)
{
    std::cout << "* uses " << this->type << " on " << target.getName() << " *" << std::endl;
}