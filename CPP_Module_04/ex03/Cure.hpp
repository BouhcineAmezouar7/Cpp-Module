#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(Cure const &other);
    Cure &operator=(const Cure &other);
    ~Cure();

    Cure *clone() const; // override clone (returns a new Cure instance)
    void use(ICharacter &target); // override use (to heal the target)
};
