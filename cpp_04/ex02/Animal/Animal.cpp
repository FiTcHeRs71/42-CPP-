#include "Animal.hpp"

/*===Canonical Form===*/
Animal::Animal(void)
	: _type("Generic Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal default destructor called" << std::endl;
}

Animal & Animal::operator=(const Animal& src)
{
	std::cout << "Animal assignement operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return(*this);
}

Animal::Animal(const Animal& to_copy)
	:_type(to_copy._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

/*===Other Constructor===*/
Animal::Animal(std::string type)
	:_type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

/*===Getters & Setters===*/
std::string Animal::getType(void)const
{
	return (this->_type);
}

/*===Member Function===*/
void	Animal::makeSound(void) const
{
	std::cout << "*Long silence*" << std::endl;
}