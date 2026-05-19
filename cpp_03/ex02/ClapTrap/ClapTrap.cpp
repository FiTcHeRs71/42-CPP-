
#include "ClapTrap.hpp"
#include <climits>
#include <ostream>

/*===Canonical Form===*/
ClapTrap::ClapTrap(void)
	: _name("Default")
	, _energPoints(10)
	, _attackDamage(0)
	, _health(10)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& to_copy)
	: _name(to_copy._name)
	, _energPoints(to_copy._energPoints)
	, _attackDamage(to_copy._attackDamage)
	, _health(to_copy._health)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name)
	, _energPoints(10)
	, _attackDamage(0)
	, _health(10)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "ClapTrap assignement oprator called" << std::endl;
	if (this != &src)
	{
		this ->_name = src._name;
		this->_attackDamage = src._attackDamage;
		this->_energPoints = src._energPoints;
		this->_health = src._health;
	}
	return (*this);
}

ClapTrap::ClapTrap(std::string name, int health, int energy, int damage)
	: _name(name)
	, _energPoints(energy)
	, _attackDamage(damage)
	, _health(health)
{
	std::cout << "ClapTrap full constructor called" << std::endl;
}

/*===Getters & Setters===*/
int	ClapTrap::getAttackDamage(void)const
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
	if (this->_energPoints >= 1)
	{
		std::cout << this->_name << " attack " << target << " causing " << this->_attackDamage << " damage and use 1 energy points, ";
		this->_energPoints -= 1;
		if (this->_energPoints <= 0)
			this->_energPoints = 0;
		std::cout << this->_energPoints << " energy points remaining" << std::endl;
	}
	else if (this->_energPoints < 1)
	{
		std::cout << this->_name << " is not able to attack cause he have no energy (" << this->_energPoints << ")" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health > 0)
	{
	if (amount >= (unsigned int)this->_health)
		this->_health = 0;
	else
		this->_health -= amount;
	std::cout << this->_name << " have recieve " << amount << " damage, " << this->_health << " remaining." << std::endl;
	if (this->_health <= 0)
		std::cout << this->_name << " DIED." << std::endl;
	}
	else if (this->_health <= 0)
	{
		std::cout << this->_name << "is already dead, stop harassing him" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_health + amount < INT_MAX && this->_health > 0)
	{
		std::cout << this->_name << " have " << this->_health << " HP and start healing himslef." << std::endl;
		this->_health += amount;
		std::cout << "Ayo yoyo ! Ayo yoyo ! Wololo wololo wololo wololo " << std::endl << this->_name << " has finished healing and now has " << this->_health << "HP" << std ::endl;
	}
	else
	{
		std::cout << this->_name << " already have max HP." <<std::endl;
	}
}