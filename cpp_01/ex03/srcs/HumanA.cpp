
#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string	name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA constructor called" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA " << this->_name << " destroyed" << std::endl;
}

void	HumanA::setWeapon(Weapon & weapon)
{
	this->_weapon = weapon;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}