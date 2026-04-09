
#include "../includes/PhoneBook.hpp"

void	Contact::print(void)const
{
	std::cout << std::endl;
	std::cout << "< First name > : " << this->_firstName << std::endl;
	std::cout << "< Last name > : " << this->_lastName << std::endl;
	std::cout << "< Nick name > : " << this->_nickName << std::endl;
	std::cout << "< Phone number > : " << this->_phone << std::endl;
	std::cout << "< Darkest secret > : " << this->_secret << std::endl;
	std::cout << std::endl;
}