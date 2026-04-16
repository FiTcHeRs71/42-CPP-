
#ifndef _ZOMBIE_HPP_
# define _ZOMBIE_HPP_

# include <iostream>
# include <iomanip>
#include <string>

class Zombie
{
private:

	std::string	_name;

public:

	/*===Constructor & Destructor===*/
	Zombie(void);
	~Zombie(void);

	/*===Getters & Setters===*/
	std::string	getZombieName(void)const;
	void		setZombieName(std::string name);

	/*=== Others ===*/
	void	announce(void);
};

	Zombie* zombieHorde( int N, std::string name );

#endif /*_ZOMBIE_HPP_*/