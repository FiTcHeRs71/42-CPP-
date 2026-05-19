#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 50; i++)
	{
		_ideas[i] = "Baby Shark too too doo";
	}
	for (int i = 50; i < 100; i++)
	{
		_ideas[i] = "Daddy Shark too too doo";
	}
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