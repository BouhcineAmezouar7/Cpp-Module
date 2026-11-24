#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    gate_keeper = false;
    hp = 100;
    ep = 50;
    ad = 20;
    std::cout << "( ScavTrap ) Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    gate_keeper = false;
    hp = 100;
    ep = 50;
    ad = 20;
    std::cout << "( ScavTrap ) the set name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "( ScavTrap ) Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->gate_keeper = other.gate_keeper;
    }
    std::cout << "( ScavTrap ) Copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "( ScavTrap ) Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (ep > 0 && hp > 0)
    {
        std::cout << "( ScavTrap ) " << name << " attacks " << target << ", causing " << ad << " points of damage!" << std::endl;
        ep--;
    }
    else if (hp == 0)
        std::cout << "( ScavTrap ) " << name << " is already dead" << std::endl;
    else
        std::cout << "( ScavTrap ) " << name << " has no energy points left and cannot attack!" << std::endl;
}

void ScavTrap::guardGate()
{
    if (hp > 0 && gate_keeper == false)
    {
        std::cout << "( ScavTrap ) " << name << " is now in Gate keeper mode" << std::endl;
        gate_keeper = true;
    }
    else if (gate_keeper == true && hp > 0)
        std::cout << "( ScavTrap ) " << name << " is already in Gate keeper mode" << std::endl;
    else
        std::cout << "( ScavTrap ) " << name << " can not save the Gate he has 0 hp" << std::endl;
}
