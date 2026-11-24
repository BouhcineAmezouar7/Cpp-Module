#pragma once

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

typedef struct s_unequipMateria
{
    AMateria *content; // pointer to unequipped materia
    struct s_unequipMateria *next;
} t_unequipMateria;

class Character : public ICharacter
{
private:
    std::string name;       // character name
    AMateria *inventory[4]; // fixed-size array for equipped materia
    t_unequipMateria *head; // linked list to store unequipped materia

public:
    Character();
    Character(const std::string &name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    ~Character();

    std::string const &getName() const;
    void equip(AMateria *m);               // equip materia
    void unequip(int idx);                 // unequip materia
    void use(int idx, ICharacter &target); // use materia
    int getMateriaCount() const;
};