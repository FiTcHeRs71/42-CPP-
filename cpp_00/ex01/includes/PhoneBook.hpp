#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:

	Contact _contact[8];
	int		_count;

public:

	//Constructor & Destructor
	PhoneBook();
	~PhoneBook();

	//Setters
	void	addContact();
	void	addContact(Contact & contact);

	//Getters
	int		getIndex(void);

	//Others
	int	contact_counter();
	std::string	addParams(std::string params);
	//void	search()const;
};

void	print_usage(void);


#endif