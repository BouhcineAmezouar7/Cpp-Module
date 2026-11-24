#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other) {
    std::cout << "Ice Copy constructor called for " << other.getType() << std::endl;
}

Ice &Ice::operator=(Ice const &other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "Ice Copy assignment operator called for " << other.getType() << std::endl;
    return *this;
}

Ice::~Ice() {
    std::cout << "Ice Destructor called for " << getType() << std::endl;
}

Ice *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
