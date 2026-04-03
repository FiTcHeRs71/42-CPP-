#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class contact
{
private:
	int				_index;
	std::string		_lastName;
	std::string		_firstName;
	std::string		_nickName;
public:
	contact();
	~contact();

	// Getters
	std::string		getLastName(void);
	std::string		getFirstName(void);
	std::string		getNickName(void);
	int				getIndex(void);

	// Setters
	void			setLastName(std::string LastName);
	void			setFirstName(std::string firstName);
	void			setNickName(std::string firstName);
	void			setIndex(int index);

};

#endif