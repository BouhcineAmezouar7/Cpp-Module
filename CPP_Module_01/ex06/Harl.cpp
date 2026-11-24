#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl's Contructed is called !!" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl's Destructer is called !!" << std::endl;
}

void Harl::debug()
{
	std::cout << "[ DEBUG ]\n " << " love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]\n " << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\n " << " think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]\n " << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	for (size_t i = 0; i < level.size(); i++)
		level[i] = toupper(level[i]);

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*functions[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};

	int index = -1;
	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			index = i;
			break;
		}
	}
	
	switch (index)
	{
	case 0:
		(this->*functions[0])();
	case 1:
		(this->*functions[1])();
	case 2:
		(this->*functions[2])();
	case 3:
		(this->*functions[3])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
