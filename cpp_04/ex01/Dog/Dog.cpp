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
	this->_myBrain = new Brain(*to_copy._myBrain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog & Dog::operator=(const Dog& src)
{
	std::cout << "Dog assigenemnt operator called" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		delete this->_myBrain;
		this->_myBrain = new Brain(*src._myBrain);
	}
	return (*this);
}

/*===Getters & Setters===*/
std::string	Dog::getMyBrainIdeas(int index)const
{
	if (index > 99)
	{
		return ("My brain is not bigger for so many ideas");
	}
	return (this->_myBrain->getIdeas(index));
}

void	Dog::setMyBrainIdeas(int index, std::string idea)
{
	if (index > 99)
	{
		std::cout << "My brain is not bigger for so many ideas";
		return;
	}
	this->_myBrain->setIdeas(index, idea);
}

/*===Member Function===*/
void	Dog::makeSound(void) const
{
	std::cout << "*Woof Woof*" << std::endl;
}
