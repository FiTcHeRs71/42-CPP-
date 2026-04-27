#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <iomanip>

class Weapon
{
	private:

	std::string _type;

	public:

	/*===Constructor & Destructor===*/
	Weapon(std::string weapon);
	~Weapon(void);

	/*===Getters & Setters===*/
	const std::string&	getType(void)const;
	void		setType(std::string type);

	/*===Others===*/
};



#endif /*__WEAPON_HPP__*/