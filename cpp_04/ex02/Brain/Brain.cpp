#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain default destructor called" << std::endl;
}

Brain::Brain(const Brain& to_copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = to_copy._ideas[i];
	}
}

Brain & Brain::operator=(const Brain& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = src._ideas[i];
		}
	}
	return (*this);
}

std::string	Brain::getIdeas(int index)const
{
	return (this->_ideas[index]);
}

void	Brain::setIdeas(int index, std::string idea)
{
	this->_ideas[index] = idea;
}
