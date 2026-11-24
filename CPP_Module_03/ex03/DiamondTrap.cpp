#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Unknown_clap_name"), FragTrap(), ScavTrap()
{
    name = "Unknown";
    hp = 100;
    ep = 50;
    ad = 30;
    std::cout << "( DiamondTrap ) Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
    this->name = name;
    hp = 100;
    ep = 50;
    ad = 30;
    std::cout << "( DiamondTrap ) the set name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    *this = other; // this->name = other.name;
    std::cout << "( DiamondTrap ) Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        this->name = other.ClapTrap::name;
        this->name = other.name;
        this->hp = other.hp;
        this->ep = other.ep;
        this->ad = other.ad;
    }
    std::cout << "( DiamondTrap ) Copy assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "( DiamondTrap ) Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
