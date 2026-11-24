#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB()
{
    // std::cout << "HumanB " << this->name << "Being destructed" << std::endl;
}

void HumanB::attack()
{
    if (this->weapon == NULL)
        std::cout << this->name << " has no weapon !!!" << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon; // assign the address of the weapon to the pointer
}