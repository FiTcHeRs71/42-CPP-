
#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_count = 0;
}

PhoneBook::~PhoneBook(){}

void	PhoneBook::search()const
{
	std::string	input;
	int			index;

	print_graphic_tab("┌", "┬", "┐");
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
		this->_contact[i].printRow(i);
	print_graphic_tab("└", "┴", "┘");
	std::cout << std::endl;
	std::cout << "Contact index : ";
	std::getline(std::cin, input);
	if (!is_number(input) || input.empty())
		return (print_error(DIGIT_ERROR));
	index = std::atoi(input.c_str());
	if (index < 0 || index > 7)
		return (print_error(DIGIT_RANGE_ERROR));
	this->_contact[index].print();
}

std::string	PhoneBook::addParams(std::string params)
{
	std::string	input;

	while (input.empty())
	{
		std::cout << params;
		if (!std::getline(std::cin, input))
			return ("");
	}
	return(input);
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
	if (std::cin.eof())
		return (print_error(MANUAL_STOP));
	contact.setLastName(addParams("LastName : "));
		if (std::cin.eof())
		return (print_error(MANUAL_STOP));
	contact.setNickName(addParams("NickName : "));
		if (std::cin.eof())
		return (print_error(MANUAL_STOP));
	contact.setPhone(addParams("Phone number : "));
		if (std::cin.eof())
		return (print_error(MANUAL_STOP));
	contact.setSecret(addParams("Darkest secret : "));
		if (std::cin.eof())
		return (print_error(MANUAL_STOP));
	this->addContact(contact);
	std::cout << "THE CONTACT HAS BEEN SUCCESFULLY SAVED AT INDEX " << (this->getIndex() - 1) % 8 << std::endl;
}