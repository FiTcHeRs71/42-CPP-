#include "Dog.hpp"

Dog::Dog(void)
	: Animal("Nafiri the Dog")
{
	this->_myBrain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete this->_myBrain;
	std::cout << "Dog default destructor called" << std::endl;
}

Dog::Dog(const Dog& to_copy)
	:Animal(to_copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog & Dog::operator=(const Dog& src)
{
	std::cout << "Dog assigenemnt operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_myBrain = src._myBrain;
	}
	return (*this);
}

/*===Member Function===*/
void	Dog::makeSound(void) const
{
	std::cout << "*Woof Woof*" << std::endl;
}