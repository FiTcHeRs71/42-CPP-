# include "Cat.hpp"

Cat::Cat(void)
	:Animal("Yumi the cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat(void)
{
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

/*===Member Function===*/
void	Cat::makeSound(void) const
{
	std::cout << "*Meow Meow*" << std::endl;
}