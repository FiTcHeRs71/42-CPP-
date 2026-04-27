
#include "../includes/Weapon.hpp"


Weapon::Weapon(std::string weapon)
{
	std::cout << "Weapon constructor called" << std::endl;
	setType(weapon);
}
Weapon::~Weapon(void)
{
	std::cout << "Weapon " << this->_type << " destroyed" << std::endl;
}
	
void	Weapon::setType(std::string type)
{
	this->_type = type;
}
const std::string&	Weapon::getType(void)const
{
	return this->_type;
}