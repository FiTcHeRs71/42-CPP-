
#include "../includes/PhoneBook.hpp"

void	print_usage(void)
{
	std::cout << "Usage :" << std::endl;
	std::cout << "ADD\t Save a new contact." << std::endl;
	std::cout << "SEARCH\t Find and display a contact of the PhoneBook." << std::endl;
	std::cout << "EXIT\t Exit this Programe made by fducrot." << std::endl;
	std::cout << std::endl;
}

void PhoneBook::addContact()
{
	Contact		contact;
	std::string	input;

	std::cout << "Please enter the following informations" << std::endl;
	std::cout << "FirstName : ";
	std::getline(std::cin, input);
	Contact::setFirstName(input);
	std::cout << "LastName : ";
	std::getline(std::cin, input);
	std::cout << "NickName : ";
	std::getline(std::cin, input);
	std::cout << "Phone number : ";
	std::getline(std::cin, input);
	std::cout << "Darkest secret : ";
	std::getline(std::cin, input);
}