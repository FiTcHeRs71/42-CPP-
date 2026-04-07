
#include "includes/PhoneBook.hpp"

int main(void)
{
	std::string	input;
	PhoneBook	phonebook;

	std::cout << "Welcome to your awesome PHONEBOOK !\n" <<  std::endl;
	print_usage();
	while (!std::cin.eof())
	{
		std::cout << "PHONEBOOK> ";
		getline(std::cin, input);
		if (input == "ADD")
		{
			phonebook.addContact();
		}
		else if (input == "SEARCH")
		{
			//phonebook.search();
		}
		else if (input == "EXIT")
		{
			std::cout << "PhoneBook is closing, Exit" << std::endl;
			exit(0);
		}
		print_usage();
	}
	return (0);
}
