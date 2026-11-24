#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other) {
    std::cout << "Cure Copy constructor called for " << other.getType() << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "Cure Copy assignment operator called for " << other.getType() << std::endl;
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure Destructor called for " << getType() << std::endl;
}

Cure *Cure::clone() const
{
    return new Cure(*this); // return a new Cure instance
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
