
#include "../includes/PhoneBook.hpp"

void	print_error(std::string error_message)
{
	std::cout << std::endl << std ::endl;
	std::cout << error_message << std::endl;
	std::cout << std::endl;
}

void	print_usage(void)
{
	std::cout << std::endl;
	std::cout << "Usage :" << std::endl;
	std::cout << "ADD\t\t Save a new contact." << std::endl;
	std::cout << "SEARCH\t\t Find and display a contact of the PhoneBook." << std::endl;
	std::cout << "EXIT\t\t Exit this wonderfull programe made by fducrot." << std::endl;
	std::cout << std::endl;
}

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

bool	is_number(std::string str)
{
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (isdigit(str[i]) <= 0)
			return (false);
	}
	return (true);
}