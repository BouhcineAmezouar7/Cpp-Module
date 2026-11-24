#include "FragTrap.hpp"

int main()
{
    // Create FragTrap
    FragTrap f1;                  // Default constructor
    FragTrap f2("SuperFrag");     // Constructor with name

    std::cout << "===================" << std::endl;

    // Attack
    f1.attack("Enemy1");
    f2.attack("Enemy2");

    std::cout << "===================" << std::endl;

    // Repair
    f1.beRepaired(100);
    f2.beRepaired(15);

    std::cout << "===================" << std::endl;

    // High Fives
    f1.highFivesGuys();
    f2.highFivesGuys();

    std::cout << "===================" << std::endl;

    // Take damage
    f1.takeDamage(150);
    f2.takeDamage(120); 

    std::cout << "===================" << std::endl;

    // High Fives after damage
    f1.highFivesGuys();
    f2.highFivesGuys();

    std::cout << "===================" << std::endl;

    return 0;
}
