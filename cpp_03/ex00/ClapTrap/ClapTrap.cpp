
#include "ClapTrap.hpp"
#include <climits>
#include <ostream>

/*===Canonical Form===*/
ClapTrap::ClapTrap(void)
	: _name("Default")
	, _energPoints(10)
	, _attackDamage(0)
	, _heatlh(10)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& to_copy)
	: _name(to_copy._name)
	, _energPoints(10)
	, _attackDamage(0)
	, _heatlh(10)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name)
	, _energPoints(10)
	, _attackDamage(0)
	, _heatlh(10)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "ClapTrap assignement oprator called" << std::endl;
	if (this != &src)
	{
		this -> _name = src._name;
	}
	return (*this);
}

/*===Getters & Setters===*/
int	ClapTrap::getAttackDamage(void)
{
	return (this->_attackDamage);
}

void	ClapTrap::setAttackDamage(int damage_amount)
{
	this->_attackDamage = damage_amount;
}

/*===Member Function===*/
void	ClapTrap::attack(const std::string& target)
{
	if (this->_energPoints >= 3)
	{
		std::cout << this->_name << " attack " << target << " causing " << this->_attackDamage << " damage and use 1 energy points, ";
		this->_energPoints -= 1;
		if (this->_energPoints <= 0)
			this->_energPoints = 0;
		std::cout << this->_energPoints << " energy points remaining" << std::endl;
	}
	else if (this->_energPoints < 3)
	{
		std::cout << this->_name << " is not able to attack cause he have no energy (" << this->_energPoints << ")" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_heatlh > 0)
	{
		this->_heatlh -= amount;
		std::cout << this->_name << " have recieve " << amount << " damage, " << this->_heatlh << " remaining." << std::endl;
		if (this->_heatlh <= 0)
			std::cout << this->_name << " DIED." << std::endl;
	}
	else if (this->_heatlh <= 0)
	{
		std::cout << this->_name << "is already dead, stop harassing him" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_heatlh + amount <= INT_MAX)
	{
		std::cout << this->_name << " have " << this->_heatlh << " HP and start healing himslef." << std::endl;
		this->_heatlh += amount;
		std::cout << "Ayo yoyo ! Ayo yoyo ! Wololo wololo wololo wololo " << std::endl << this->_name << " has finished healing and now has " << this->_heatlh << "HP" << std ::endl;
	}
	else
	{
		std::cout << this->_name << " already have max HP." <<std::endl;
	}
}