#include "ICharacter.hpp"
#include "../AMateria/AMateria.hpp"

/***** CHARACTER CLASS *****/
/*===Canonical Form===*/
Character::Character(void)
	:_name("Default name")
{
	for (int i = 0; i < SLOT_INVENTORY; i++)
		this->_inventory[i] = NULL;
	//std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name)
	:_name(name)
{
	for (int i = 0; i < SLOT_INVENTORY; i++)
		this->_inventory[i] = NULL;
	//std::cout << "Character full constructor called" << std::endl;
}

Character::Character(const Character& to_copy)
	:ICharacter(), _name(to_copy._name)
{
	for (int i = 0; i < SLOT_INVENTORY; i++)
	{
		if (to_copy._inventory[i])
			this->_inventory[i] = to_copy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	//std::cout << "Character copy constructor called" << std::endl;
}

Character & Character::operator=(const Character& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < SLOT_INVENTORY; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	//std::cout << "Character assignement operator(=) called" << std::endl;
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < SLOT_INVENTORY; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	//std::cout << "Character default destructor called" << std::endl;
}

/*===Getters & Setters===*/
std::string const & Character::getName() const
{
	return (this->_name);
}

/*===Member Function===*/
void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "* " << this->_name << " tries to equip nothing *" << std::endl;
		return ;
	}
	for (int i = 0; i < SLOT_INVENTORY; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << "* " << this->_name << " equips " << m->getType()
				<< " in slot " << i << " *" << std::endl;
			return ;
		}
	}
	std::cout << "* " << this->_name << "'s inventory is full, cannot equip "
		<< m->getType() << " *" << std::endl;
	delete m;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= SLOT_INVENTORY || this->_inventory[idx] == NULL)
	{
		std::cout << "* " << this->_name << " has no materia in slot " << idx << " *" << std::endl;
		return ;
	}
	std::cout << "* " << this->_name << " unequips materia from slot " << idx << " *" << std::endl;
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= SLOT_INVENTORY || this->_inventory[idx] == NULL)
	{
		std::cout << "* " << this->_name << " has no materia in slot " << idx << " to use *" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}
