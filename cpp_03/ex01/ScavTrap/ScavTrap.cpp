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

ScavTrap::ScavTrap(const ScavTrap& ScavTrap)
	: ClapTrap(ScavTrap._name)
	, _attackDamage(ScavTrap._attackDamage)
{

}

ScavTrap & ScavTrap::operator=(const ScavTrap & ScavTrap)
{

}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_heatlh = 100;
	this->_energPoints = 50;
	this->_attackDamage = 20;
}