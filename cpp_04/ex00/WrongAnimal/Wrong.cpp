#include "Wrong.hpp"

WrongAnimal::WrongAnimal(void)
	:_type("Wronger")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal default destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& to_copy)
	:_type(to_copy._type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

void	WrongAnimal::makeSound(void)
{
	std::cout << "I'm a Wromg Animal" << std::endl;
}

WrongCat::WrongCat(void)
	:WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& to_copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat& src)
{
	if (this != &src)
	{
		WrongAnimal::operator=(src);
	}
	return (*this);
}

void	WrongCat::makeSound(void)
{
	std::cout << "I'm a wrong cat" << std::endl;
}