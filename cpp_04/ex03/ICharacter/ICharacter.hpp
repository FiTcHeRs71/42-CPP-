#ifndef __ICHARACTER_HPP__
# define __ICHARACTER_HPP__

# include <iostream>
# include <string>

# define SLOT_INVENTORY 4

class AMateria;

class ICharacter
{
	public:

	virtual ~ICharacter() {}

	/*===Getters & Setters===*/
	virtual std::string const & getName() const = 0;

	/*===Member Function===*/
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
	private:

	std::string	_name;
	AMateria	*_inventory[SLOT_INVENTORY];

	protected:



	public:

	/*===Canonical Form===*/
	Character(void);
	~Character(void);
	Character(const Character& to_copy);
	Character&operator=(const Character& src);
	Character(std::string name);

	/*===Getters & Setters===*/
	std::string const & getName() const;

	/*===Member Function===*/
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif /*__ICHARACTER_HPP__*/