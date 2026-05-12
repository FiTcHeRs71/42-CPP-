#ifndef __SCAV_TRAP__
# define __SCAV_TRAP__

# include "../ClapTrap/ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
	public:

	/*===Canonical Form===*/
	ScavTrap(void);
	~ScavTrap(void);
	ScavTrap(const ScavTrap& ScavTrap);
	ScavTrap &operator=(const ScavTrap & ScavTrap);

	/*===Member Function===*/
	void	guardGate();

};

#endif /*__SCAV_TRAP__*/