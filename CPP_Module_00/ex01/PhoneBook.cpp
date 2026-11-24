#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook()
{
	count = 0;
	index = 0;
}

int PhoneBook::getcount()
{
	return (count);
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact()
{
	bool	valid;

	std::string first, last, nick, phone, secret;
	while (first.empty())
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, first);
		if (std::cin.eof())
			return ;
	}
	while (last.empty())
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, last);
		if (std::cin.eof())
			return ;
	}
	while (nick.empty())
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nick);
		if (std::cin.eof())
			return ;
	}
	while (phone.empty())
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phone);
		valid = true;
		for (size_t i = 0; i < phone.length(); i++)
		{
			if (!isdigit(phone[i]) && phone[i] != '+' && phone[i] != '-'
				&& phone[i] != ' ')
			{
				valid = false;
				break ;
			}
		}
		if (!valid)
		{
			std::cout << "Invalid phone number. Please enter digits only." << std::endl;
			phone.clear();
			continue ;
		}
		if (std::cin.eof())
			return ;
	}
	while (secret.empty())
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, secret);
		if (std::cin.eof())
			return ;
	}
	contacts[index % 8].setInfo(first, last, nick, phone, secret);
	index++;
	if (count < 8)
		count++;
	std::cout << "Contact added!" << std::endl;
}

void PhoneBook::displayContact(int i)
{
	if (i < 0 || i >= count)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	std::cout << "First Name: " << contacts[i].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[i].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[i].getDarkestSecret() << std::endl;
}

static std::string formatField(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

void PhoneBook::searchContacts()
{
	if (count == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------\n";
	std::cout << "| Index |First Name| Last Name| Nickname |\n";
	std::cout << "---------------------------------------------\n";
	for (int i = 0; i < count; i++)
	{
		std::cout << "|   " << i << "   |" << std::setw(10) << formatField(contacts[i].getFirstName()) << "|" << std::setw(10) << formatField(contacts[i].getLastName()) << "|" << std::setw(10) << formatField(contacts[i].getNickname()) << "|\n";
	}
	std::cout << "---------------------------------------------\n";
}
