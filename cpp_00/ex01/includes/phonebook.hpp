#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "contact.hpp"

class PhoneBook
{
private:

	Contact _contact[8];
	int		count;

public:

	PhoneBook();
	~PhoneBook();

	//Setters
	void	addContact(
		std::string lastName,
		std::string firstName,
		std::string nickName,
		std::string phone,
		std::string secret
		);
	void	search();
};




#endif