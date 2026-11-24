#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void	replace(std::string filename, std::string s1, std::string s2)
{
	size_t	pos;

	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return ;
	}
	std::string out_filename = filename + ".replace";
	std::ofstream outfile(out_filename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: Could not create file " << out_filename << std::endl;
		infile.close();
		return ;
	}
	std::ostringstream buff;
	buff << infile.rdbuf();
	std::string content = buff.str();
	pos = 0;
	while (!s1.empty() && (pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}
	infile.close();
	outfile << content;
	outfile.close();
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./Sed <filename> <s1> <s2>\n";
		return (1);
	}

	replace(av[1], av[2], av[3]);
}