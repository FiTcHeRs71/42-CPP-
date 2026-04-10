#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/* ==================== LIBRAIRIES & HEADERS ==================== */

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

/* ==================== MESSAGES ==================== */

# define DIGIT_ERROR "Please enter only digit characters."
# define DIGIT_RANGE_ERROR "Please select a contact between 1 and 8 range."
# define MANUAL_STOP "Manual interruption, the contact has not been added."


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
	void		addContact();
	void		addContact(Contact & contact);

	//Getters
	int			getIndex(void);

	//Others
	int			contact_counter();
	std::string	addParams(std::string params);
	void		search()const;
};

void			print_usage(void);
void			print_error(std::string error_message);
bool			is_number(std::string str);

#endif