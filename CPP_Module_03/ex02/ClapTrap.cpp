#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hp(10), ep(10), ad(0)
{
    std::cout << "the Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string &name) : name(name), hp(10), ep(10), ad(0)
{
    std::cout << "the set name constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
    : name(other.name), hp(other.hp), ep(other.ep), ad(other.ad)
{
    std::cout << "the Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other) // self-assignment check
    {
        this->name = other.name;
        this->hp = other.hp;
        this->ep = other.ep;
        this->ad = other.ad;
    }
    std::cout << "the Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "the Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (ep > 0 && hp > 0)
    {
        std::cout << "( ClapTrap ) " << name << " attacks " << target << ", causing " << ad << " points of damage!" << std::endl;
        ep--;
    }
    else if (hp == 0)
        std::cout << "( ClapTrap ) " << name << " is already dead" << std::endl;
    else
        std::cout << "( ClapTrap ) " << name << " has no energy points left and cannot attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hp == 0)
        std::cout << "( ClapTrap ) " << name << " is already dead" << std::endl;
    else if (amount > hp) // amount of damage like more than current hp
    {
        hp = 0;
        std::cout << "( ClapTrap ) " << name << " takes " << amount << " points of damage and is now dead!" << std::endl;
    }
    else
    {
        hp -= amount;
        std::cout << "( ClapTrap ) " << name << " takes " << amount << " points of damage! HP is now " << hp << "." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hp == 0)
        std::cout << "( ClapTrap ) " << name << " is dead and cannot be repaired." << std::endl;
    else if (ep > 0 && hp > 0)
    {
        if (hp + amount > 100)
            hp = 100;
        else
            hp += amount;
        ep--;
        std::cout << "( ClapTrap ) " << name << " is repaired by " << amount << " points! HP is now " << hp << "." << std::endl;
    }
    else if (hp == 10)
        std::cout << "( ClapTrap ) " << name << " already has full health." << std::endl;

    else
        std::cout << "( ClapTrap ) " << name << " has no energy points left and cannot be repaired!" << std::endl;
}
