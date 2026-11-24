#include "Contact.hpp"

Contact::Contact()
{
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNumber = "";
	darkestSecret = "";
}

Contact::~Contact()
{
}

void Contact::setInfo(std::string first, std::string last, std::string nick,
	std::string phone, std::string secret)
{
	firstName = first;
	lastName = last;
	nickname = nick;
	phoneNumber = phone;
	darkestSecret = secret;
}

std::string Contact::getFirstName()
{
	return (firstName);
}
std::string Contact::getLastName()
{
	return (lastName);
}
std::string Contact::getNickname()
{
	return (nickname);
}

std::string Contact::getPhoneNumber()
{
	return (phoneNumber);
}
std::string Contact::getDarkestSecret()
{
	return (darkestSecret);
}
