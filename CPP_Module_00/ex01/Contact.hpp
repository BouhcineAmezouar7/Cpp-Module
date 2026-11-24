#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

  public:
	Contact();
	void setInfo(std::string first, std::string last, std::string nick,
		std::string phone, std::string secret);
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string getDarkestSecret();

	~Contact();
};

#endif