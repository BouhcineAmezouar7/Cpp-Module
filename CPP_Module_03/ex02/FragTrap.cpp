#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	hp = 100;
	ep = 100;
	ad = 30;
	std::cout << "( FragTrap ) Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	hp = 100;
	ep = 100;
	ad = 30;
	std::cout << "( FragTrap ) the set name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "( FragTrap ) Copy constructor called" << std::endl;
}
FragTrap::~FragTrap()
{
	std::cout << "( FragTrap ) the destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "( FragTrap ) Copy assignment operator called" << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (hp > 0)
		std::cout << "he guys, give me high five!" << std::endl;
	else
		std::cout << "( FragTrap ) " << name << " is already dead" << std::endl;
}