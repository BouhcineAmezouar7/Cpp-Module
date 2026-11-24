#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
private:
    std::string name;
    unsigned int hp; // hit points
    unsigned int ep; // energy points
    unsigned int ad; // attack damage

public:
    ClapTrap(); // default constructor
    ClapTrap(const std::string &name); // parameterized constructor
    ClapTrap(const ClapTrap &other); // copy constructor
    ClapTrap &operator=(const ClapTrap &other); // copy assignment operator
    ~ClapTrap(); // destructor

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
