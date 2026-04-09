
#include "../includes/PhoneBook.hpp"

void	PhoneBook::initCount()
{
	this->_count = 0;
}

int	PhoneBook::contact_counter()
{
	this->_count++;
	return(this->_count % 8);
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

void	PhoneBook::addContact(Contact & concact)
{
	this->_contact[contact_counter()] = concact;
}

void	PhoneBook::addContact()
{
	Contact		contact;
	std::string	input;

	std::cout << "Please enter the following informations" << std::endl;

	std::cout << "FirstName : ";
	std::getline(std::cin, input);
	contact.setFirstName(input);

	std::cout << "LastName : ";
	std::getline(std::cin, input);
	contact.setLastName(input);

	std::cout << "NickName : ";
	std::getline(std::cin, input);
	contact.setNickName(input);

	std::cout << "Phone number : ";
	std::getline(std::cin, input);
	contact.setPhone(input);

	std::cout << "Darkest secret : ";
	std::getline(std::cin, input);
	contact.setSecret(input);

	this->addContact(contact);
	std::cout << "THE CONTACT HAS BEEN SUCCESFULLY SAVED" << std::endl;
}