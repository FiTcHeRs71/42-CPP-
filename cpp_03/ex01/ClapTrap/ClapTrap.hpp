#ifndef __CLAP_TRAP_HPP__
# define __CLAP_TRAP_HPP__

# include <iostream>
#include <string>

class	ClapTrap
{
	protected:

	std::string	_name;
	int			_energPoints;
	int			_attackDamage;
	int			_health;

	public:

	/*===Canonical Form===*/
	ClapTrap(void);
	virtual ~ClapTrap(void);
	ClapTrap(const ClapTrap& to_copy);
	ClapTrap &operator=(const ClapTrap& src);
	ClapTrap(std::string name);

	/*===Getters & Setters===*/
	int			getAttackDamage(void)const;
	void		setAttackDamage(int damage_amount);

	/*===Member Function===*/
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};

#endif /*__CLAP_TRAP_HPP__*/