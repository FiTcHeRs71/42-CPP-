
#include "ClapTrap.hpp"
#include <ostream>

/*===Canonical Form===*/
ClapTrap::ClapTrap(void)
	: _name("Default")
	, _energPoints(10)
	, _heatlh(10)
	, _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& to_copy) : _name(to_copy._name)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap& ClapTrap)
{
	std::cout << "ClapTrap assignement oprator called" << std::endl;
	if (this != &ClapTrap)
	{
		this -> _name = ClapTrap._name;
	}
	return (*this);
}

/*===Member Function===*/
void	ClapTrap::attack(const std::string& target)
{
	if (this->_energPoints > 0)
	{
		std::cout << this->_name << " attack " << target << " causing " << this->_attackDamage << " damage and use " << this->_energPoints << std::endl;
	}
	else if (this->_energPoints <=0)
	{
		std::cout << this->_name << " is not able to attack cause he have no energy (" << this->_energPoints << ")" << std::endl;
	}
}
