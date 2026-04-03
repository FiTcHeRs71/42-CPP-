#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>

class contact
{
private:
	std::string		_lastName;
	std::string		_firstName;
	long long int	_number;

public:
	contact();
	~contact();

	// _LastName
	std::string		getLastName(void);
	void			setLastName(std::string LastName);

	//_FirstName
	std::string		getFirstName(void);
	void			setFirstName(std::string firstName);

	//_Number
	long long int	getNumber(void);
	void			setNumber(long long int number);
};

#endif