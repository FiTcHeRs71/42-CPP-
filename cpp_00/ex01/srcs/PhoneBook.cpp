
#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_count = 0;
}

PhoneBook::~PhoneBook(){}

int	PhoneBook::getIndex(void)
{
	return this->_count;
}

int	PhoneBook::contact_counter()
{
	int	pos_index = this->_count % 8;
	this->_count++;
	return(pos_index);
}

std::string	PhoneBook::addParams(std::string params)
{
	std::string	input;
	while (input.empty())
	{
		std::cout << params;
		if (!std::getline(std::cin, input))
			continue;
	}
	return(input);
}

void	print_usage(void)
{
	std::cout << std::endl;
	std::cout << "Usage :" << std::endl;
	std::cout << "ADD\t Save a new contact." << std::endl;
	std::cout << "SEARCH\t Find and display a contact of the PhoneBook." << std::endl;
	std::cout << "EXIT\t Exit this Programe made by fducrot." << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::addContact(Contact & contact)
{
	this->_contact[contact_counter()] = contact;
}

void	PhoneBook::addContact()
{
	Contact		contact;
	std::string	input;

	std::cout << "Please enter the following informations" << std::endl;
	contact.setFirstName(addParams("FirstName : "));
	contact.setLastName(addParams("LastName : "));
	contact.setNickName(addParams("NickName : "));
	contact.setPhone(addParams("Phone number : "));
	contact.setSecret(addParams("Darkest secret : "));
	this->addContact(contact);
	std::cout << "THE CONTACT HAS BEEN SUCCESFULLY SAVED AT INDEX " << this->getIndex() - 1 << std::endl;
}