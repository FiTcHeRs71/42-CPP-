
#include "../includes/PhoneBook.hpp"

void	Contact::setFirstName(std::string firstname)
{
	this->_firstName = firstname;
}

void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	this->_nickName= nickName;
}

void	Contact::setPhone(std::string phone)
{
	this->_phone = phone;
}

void	Contact::setSecret(std::string secret)
{
	this->_secret = secret;
}

std::string		Contact::getLastName(void)const
{
	return this->_lastName;
}

std::string		Contact::getFirstName(void)const
{
	return this->_firstName;
}

std::string		Contact::getNickName(void)const
{
	return this->_nickName;
}

std::string		Contact::getPhone(void)const
{
	return this->_phone;
}

std::string		Contact::getSecret(void)const
{
	return this->_secret;
}
