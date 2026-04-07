#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
private:

	Contact _contact[8];
//	int		_count;

public:

	//Setters
	void	addContact();
	//void	search()const;
};

void	print_usage(void);


#endif