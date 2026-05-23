# include "Cat.hpp"

Cat::Cat(void)
	:Animal("Yumi the cat")
{
	this->_myBrain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat(void)
{
	delete this->_myBrain;
	std::cout << "Cat default destructor called" << std::endl;
}

Cat::Cat(const Cat& to_copy)
	:Animal(to_copy)
{
	if (this->_myBrain)
		delete this->_myBrain;
	this->_myBrain = new Brain(*(to_copy._myBrain));
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat & Cat::operator=(const Cat& src)
{
	std::cout << "Cat operator assignement called" << std::endl;
	if (this != &src)
	{
		if (this->_myBrain)
			delete this->_myBrain;
		for (int i = 0; i < 100; i++)
			this->_myBrain = src._myBrain;
	}
	return(*this);
}

/*===Getters & Setters===*/
std::string	Cat::getMyBrainIdeas(int index)const
{
	if (index > 99)
	{
		return ("My brain is not bigger for so many ideas");
	}
	return (this->_myBrain->getIdeas(index));
}

void	Cat::setMyBrainIdeas(int index, std::string idea)
{
	if (index > 99)
	{
		std::cout << "My brain is not bigger for so many ideas";
		return;
	}
	this->_myBrain->setIdeas(index, idea);
}

/*===Member Function===*/
void	Cat::makeSound(void) const
{
	std::cout << "*Meow Meow*" << std::endl;
}