#include "Character.hpp"

Character::Character() : name("Default"), head(NULL)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
    std::cout << "Character Default constructor called" << std::endl;
}

Character::Character(const std::string &name) : name(name), head(NULL)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
    std::cout << "Character Parameterized constructor called for " << name << std::endl;
}

Character::Character(const Character &other) : name(other.name), head(NULL)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    std::cout << "Character Copy constructor called for " << name << std::endl;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (inventory[i])
                delete inventory[i];
            inventory[i] = NULL;
        }
        for (int i = 0; i < 4; ++i)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
        this->name = other.name;
    }
    std::cout << "Character Copy assignment operator called for " << name << std::endl;
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
    {
        if (inventory[i])
            delete inventory[i];
    }
    t_unequipMateria *current = head;
    while (current)
    {
        t_unequipMateria *next = current->next;
        delete current->content;
        delete current;
        current = next;
    }
    std::cout << "Character Destructor called for " << name << std::endl;
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;

    // check if address of m already exists in inventory
    for (int i = 0; i < 4; ++i)
    {
        if (inventory[i] == m)
            return;
    }
    // check if address of m already exists in unequipped list
    t_unequipMateria *current = head;
    while (current)
    {
        if (current->content == m)
            return;
        current = current->next;
    }
    // try to equip in first empty slot
    for (int i = 0; i < 4; ++i)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
    t_unequipMateria *newNode = new t_unequipMateria;
    newNode->content = m;
    newNode->next = NULL;
    if (!head)
    {
        head = newNode;
        return;
    }
    // add to the end of the linked list
    current = head;
    while (current->next)
        current = current->next;
    current->next = newNode;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;

    t_unequipMateria *newNode = new t_unequipMateria;
    newNode->content = inventory[idx];
    newNode->next = NULL;

    inventory[idx] = NULL;
    if (!head)
    {
        head = newNode;
        return;
    }
    t_unequipMateria *current = head;
    while (current->next)
        current = current->next;
    current->next = newNode;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    inventory[idx]->use(target);
}
