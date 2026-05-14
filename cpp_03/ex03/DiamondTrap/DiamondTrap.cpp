#include "DiamondTrap.hpp"

/*===Canonical Form===*/
DiamondTrap::DiamondTrap(void)
	: ClapTrap()
{
	std::cout << "DiamondTrap  default constructor called" << std::endl;
}
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap default destructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& to_copy)
	: ClapTrap(to_copy)
	, FragTrap(to_copy)
	, ScavTrap(to_copy)
{
	std::cout << "DiamondTrap  copy constructor called" << std::endl;
}
DiamondTrap & DiamondTrap::operator=(const DiamondTrap& src)
{
	std::cout << "DiamondTrap  assignement operator constructor called" << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name)
	, _name(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
}

/*===Member Function===*/
void	DiamondTrap::whoAmI()
{
	std::cout << "Hello dear friens my name is " << this->_name << std::endl;
}