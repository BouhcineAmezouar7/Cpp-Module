#pragma once

#include <string>
#include <iostream>
#include "ICharacter.hpp"


class ICharacter;

class AMateria
{
protected:
    std::string type;

public:
    AMateria();                                 // default constructor
    AMateria(std::string const &type);          // parameterized constructor
    AMateria(AMateria const &other);            // copy constructor
    AMateria &operator=(AMateria const &other); // copy assignment operator
    virtual ~AMateria();                        // virtual destructor
    std::string const &getType() const;
    virtual AMateria *clone() const = 0;       // virtual + = 0 for abstract
    virtual void use(ICharacter &target);     // virtual for overriding
};