#ifndef __FRAG_TRAP_HPP__
# define __FRAG_TRAP_HPP__

# include "../ClapTrap/ClapTrap.hpp"
# include <iostream>
#include <string>

class FragTrap : public ClapTrap
{
	public:

	/*===Canonical Form===*/
	FragTrap(void);
	~FragTrap(void);
	FragTrap(const FragTrap& to_copy);
	FragTrap&operator=(const FragTrap& src);
	FragTrap(std::string name);

	/*===Member Function===*/
	void	highFiveGuys(void);
};

#endif /*__FRAG_TRAP_HPP__*/