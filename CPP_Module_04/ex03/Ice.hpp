#pragma once

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(Ice const &other);
    Ice &operator=(Ice const &other);
    ~Ice();

    Ice *clone() const;
    void use(ICharacter &target);
};
