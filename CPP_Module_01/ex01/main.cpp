#include "Zombie.hpp"

int	main(void)
{
	int N = 3;
	std::string name = "Walker";

	Zombie *horde = zombieHorde(N, name);

	delete[] horde;

	return (0);
}