#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "contact.hpp"

class phonebook
{
private:
	contact _contact[8];
	int		count;
public:
	phonebook();
	~phonebook();
};




#endif