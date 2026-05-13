#include "ScavTrap.hpp"

/*===Canonical Form===*/
ScavTrap::ScavTrap(void)
	: ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_heatlh = 100;
	this->_energPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap default destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& to_copy)
	: ClapTrap(to_copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & src)
{
	std::cout << "ScavTrap assignement oprator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_attackDamage = src._attackDamage;
		this->_energPoints = src._energPoints;
		this->_heatlh = src._heatlh;
	}
	return (*this);
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "ScavTrap constructor called." << std::endl;
	this->_heatlh = 100;
	this->_energPoints = 50;
	this->_attackDamage = 20;
}

void	ScavTrap::guardGate()
{
	std::cout << this->_name << " switch in Gate keeper mode and increase his hp." << std::endl;
	this->_heatlh += 50;
	std::cout << this->_name << " : You shall not pass" << std::endl;
}