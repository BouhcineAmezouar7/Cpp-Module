#include <iostream>

int	main(int ac, char **av)
{
	int		i;
	size_t	j;

	i = 1;
	j = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < ac)
		{
			j = 0;
			while (av[i][j])
			{
				av[i][j] = toupper(av[i][j]);
				j++;
			}
			std::cout << av[i];
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
