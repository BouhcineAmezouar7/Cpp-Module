#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl obj;

	if (ac == 2)
		obj.complain(av[1]);
	else
		std::cout << "Invalid number of arguments" << std::endl;
	return (0);
}
