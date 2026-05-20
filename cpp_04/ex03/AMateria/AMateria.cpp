#include "AMateria.hpp"

/*===Canonical Form===*/
AMateria::AMateria(void)
	:_type("Default AMateria")
{
	std::cout << "AMateria default constructor called" << std::endl;
}
AMateria::~AMateria(void)
{
	std::cout << "AMateria default destructor called" << std::endl;
}
AMateria::AMateria(const AMateria& to_copy)
	:_type(to_copy._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}
AMateria & AMateria::operator=(const AMateria& src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	return(*this);
}

/*===Others constructor===*/
AMateria::AMateria(std::string const & type)
	:_type(type)
{
	std::cout << "AMateria full constructor called" << std::endl;
}

/*===Getters & Setters===*/
std::string const & AMateria::getType()const
{
	return (this->_type);
}

/*===Member Function===*/
//virtual AMateria* clone() const = 0;
void	AMateria::use(ICharacter& target)
{
	// a completer 
}