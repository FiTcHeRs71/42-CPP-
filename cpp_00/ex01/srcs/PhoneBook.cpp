
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

	std::cout << "FirstName : ";
	std::getline(std::cin, input);
	if(input.empty())
	{
		std::cout << "The field cannot be empty " << std::endl;
		return ;
	}
	contact.setFirstName(input);

	std::cout << "LastName : ";
	std::getline(std::cin, input);
	if(input.empty())
	{
		std::cout << "The field cannot be empty " << std::endl;
		return ;
	}
	contact.setLastName(input);

	std::cout << "NickName : ";
	std::getline(std::cin, input);
	if(input.empty())
	{
		std::cout << "The field cannot be empty " << std::endl;
		return ;
	}
	contact.setNickName(input);

	std::cout << "Phone number : ";
	std::getline(std::cin, input);
	if(input.empty())
	{
		std::cout << "The field cannot be empty " << std::endl;
		return ;
	}
	contact.setPhone(input);

	std::cout << "Darkest secret : ";
	std::getline(std::cin, input);
	if(input.empty())
	{
		std::cout << "The field cannot be empty " << std::endl;
		return ;
	}
	contact.setSecret(input);

	this->addContact(contact);
	std::cout << "THE CONTACT HAS BEEN SUCCESFULLY SAVED AT INDEX " << PhoneBook::getIndex() - 1 << std::endl;
}