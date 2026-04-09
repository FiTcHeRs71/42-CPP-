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
	int	contact_counter();

	//Getters
	int		getIndex(void);
	//void	search()const;
};

void	print_usage(void);


#endif