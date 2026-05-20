#ifndef __ICHARACTER_HPP__
# define __ICHARACTER_HPP__

# include <iostream>

class AMateria;

class ICharacter
{
	private:

	std::string	_name;

	protected:
	

	public:

	/*===Canonical Form===*/
	ICharacter(void);
	virtual ~ICharacter(void);
	ICharacter(const ICharacter& to_copy);
	ICharacter&operator=(const ICharacter& src);

	/*===Getters & Setters===*/
	virtual std::string const & getName() const = 0;

	/*===Member Function===*/
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif /*__ICHARACTER_HPP__*/