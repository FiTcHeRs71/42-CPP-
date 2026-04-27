
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
	Zombie(std::string name);
	~Zombie(void);

	/*===Getters & Setters===*/
	std::string	getZombieName(void)const;
	void		setZombieName(std::string name);

	/*===Others===*/
	void	announce(void);

};

	Zombie* newZombie( std::string name );
	/*This function creates a zombie, names it, and returns it so you can use it outside
of the function scope.*/
	void randomChump( std::string name );
	/*This function creates a zombie, names it, and makes it announce itself.*/

#endif /*_ZOMBIE_HPP_*/