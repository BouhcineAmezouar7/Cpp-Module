#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Paboo");
    ClapTrap b("Bot");

    a.attack("Bot");
    b.takeDamage(5);
    b.beRepaired(3);
    a.attack("Bot");
    b.takeDamage(8);
    b.beRepaired(5);
}
