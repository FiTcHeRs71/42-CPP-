
#include "includes/PhoneBook.hpp"

int main(void)
{
	std::string	input;
	PhoneBook	phonebook;

	std::cout << "Welcome to your awesome PHONEBOOK !\n" <<  std::endl;
	while (!std::cin.eof())
	{
		print_usage();
		std::cout << "PHONEBOOK> ";
		getline(std::cin, input);
		if (input == "ADD")
		{
			phonebook.addContact();
		}
		else if (input == "SEARCH")
		{
			phonebook.search();
		}
		else if (input == "EXIT")
		{
			std::cout << "PhoneBook is closing, Exit" << std::endl;
			return(0);
		}
	}
	std::cout << "Exit this wonderfull programe made by fducrot." << std::endl;
	return (0);
}
