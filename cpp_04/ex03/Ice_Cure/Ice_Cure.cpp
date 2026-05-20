#include "Ice_Cure.hpp"
/***** ICE ******/
/*===Canonical Form===*/
Ice::Ice(void)
	:AMateria("ice")
{
	//std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice(void)
{
	//std::cout << "Ice default destructor called" << std::endl;
}

Ice::Ice(const Ice& to_copy)
	:AMateria(to_copy)
{
	//std::cout << "Ice copy constructor called" << std::endl;
}

Ice & Ice::operator=(const Ice& src)
{
	if (this != &src)
	{
		AMateria::operator=(src);
	}
	return(*this);
}

/*===Member Function===*/
AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/***** CURE ******/
/*===Canonical Form===*/
Cure::Cure(void)
	:AMateria("cure")
{
	//std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure(void)
{
	//std::cout << "Cure default destructor called" << std::endl;
}

Cure::Cure(const Cure& to_copy)
	:AMateria(to_copy)
{
	//std::cout << "Cure copy constructor called" << std::endl;
}
Cure & Cure::operator=(const Cure& src)
{
	if (this != &src)
	{
		AMateria::operator=(src);
	}
	return (*this);
}

/*===Member Function===*/
AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}
void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}