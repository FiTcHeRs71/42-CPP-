#include "FragTrap.hpp"

	/*===Canonical Form===*/
FragTrap::FragTrap(void)
	: ClapTrap()
{
	std::cout << "FragTrap default constructor called." << std::endl;
	this->_health = 100;
	this->_energPoints = 100;
	this->_attackDamage = 30;
}
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap default destructor called." << std::endl;
}
FragTrap::FragTrap(const FragTrap& to_copy)
	: ClapTrap(to_copy)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap& src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return(*this);
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name, 100, 100, 30)
{
		std::cout << "FragTrap constructor called." << std::endl;
}

	/*===Member Function===*/
void	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->_name << ": You want a high five?\n\t*WHAMM*\nHere you go." << std::endl;
}