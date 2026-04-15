
#include "Zombie.hpp"

/*== Constructor & Destructor ==*/
Zombie::Zombie(void) 
{
	std::cout << "Zombie construstor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "destructor called for : " << this->_name << std::endl;
}

/*=== Getters & Setters ===*/
std::string	Zombie::getZombieName(void)const
{
	return this->_name;
}

void	Zombie::setZombieName(std::string name)
{
	this->_name = name;
}

/*== Others ==*/
void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

