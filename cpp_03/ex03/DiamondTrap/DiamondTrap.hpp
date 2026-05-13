#ifndef __DIAMOND_TRAP_HPP__
# define __DIAMOND_TRAP_HPP__

# include "../ClapTrap/ClapTrap.hpp"
# include "../FragTrap/FragTrap.hpp"
# include "../ScavTrap/ScavTrap.hpp"
# include <iostream>
# include <string>

class	DiamondTrap : public FragTrap, public ScavTrap
{
	private :

	std::string	_name;

	public:

	/*===Canonical Form===*/
	DiamondTrap(void);
	~DiamondTrap(void);
	DiamondTrap(const DiamondTrap& to_copy);
	DiamondTrap &operator=(const DiamondTrap& src);
	DiamondTrap(std::string name);

	/*===Member Function===*/
	void		whoAmI();

};

#endif /*__DIAMOND_TRAP_HPP__*/