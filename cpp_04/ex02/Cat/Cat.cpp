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
	std::cout << "Cat copy constructor called" <<std::endl;
}

Cat & Cat::operator=(const Cat& src)
{
	std::cout << "Cat operator assignement called" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
	}
	return(*this);
}

/*===Getters & Setters===*/
std::string		Cat::getMyBrainIdeas(int index)const
{
	return (this->_myBrain->getIdeas(index));
}


/*===Member Function===*/
void	Cat::makeSound(void) const
{
	std::cout << "*Meow Meow*" << std::endl;
}