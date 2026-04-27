#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"

class	HumanA
{
	private:

	std::string	_name;
	Weapon		&_weapon;

	public:

	/*===Constructor & Destructor===*/
	HumanA(std::string	name, Weapon &weapon);
	~HumanA(void);

	/*=== Others ===*/
	void	attack(void);
};


#endif
