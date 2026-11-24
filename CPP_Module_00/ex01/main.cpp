#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	PhoneBook phonebook;

	std::string command;
	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			break;
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
		{
			phonebook.searchContacts();
			if (std::cin.eof())
				break;
			if (phonebook.getcount() != 0)
			{
				std::cout << "Enter index of contact to display: ";
				std::string index_str;
				std::getline(std::cin, index_str);
				if (std::cin.eof())
					break;
				if (index_str.length() != 1 || !isdigit(index_str[0]))
				{
					std::cout << "Invalid index." << std::endl;
					continue;
				}
				int index = index_str[0] - '0';
				phonebook.displayContact(index);
			}
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}