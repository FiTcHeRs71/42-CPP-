
#include "../includes/HumanB.hpp"


HumanB::HumanB(std::string	name)
{
		std::cout << "HumanB constructor called" << std::endl;
	this->_name = name;
}
HumanB::~HumanB()
{
	std::cout << "HumanB " << this->_name << " destroyed" << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon & weapon)
{
	this->_weapon = &weapon;
}