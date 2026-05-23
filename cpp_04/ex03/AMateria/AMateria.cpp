#include "AMateria.hpp"

/***** AMATERIA CLASS *****/
/*===Canonical Form===*/
AMateria::AMateria(void)
	:_type("Default AMateria")
{
	//std::cout << "AMateria default constructor called" << std::endl;
}
AMateria::~AMateria(void)
{
	//std::cout << "AMateria default destructor called" << std::endl;
}
AMateria::AMateria(const AMateria& to_copy)
	:_type(to_copy._type)
{
	//std::cout << "AMateria copy constructor called" << std::endl;
}
AMateria & AMateria::operator=(const AMateria& src)
{
	(void)src;
	return(*this);
}

/*===Others constructor===*/
AMateria::AMateria(std::string const & type)
	:_type(type)
{
	//std::cout << "AMateria full constructor called" << std::endl;
}

/*===Getters & Setters===*/
std::string const & AMateria::getType()const
{
	return (this->_type);
}

/*===Member Function===*/
void	AMateria::use(ICharacter& target)
{
	(void)target;
}

/***** MATERIASOURCE CLASS *****/
/*===Canonical Form===*/
MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_learnInventory[i] = NULL;
	//std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& to_copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (to_copy._learnInventory[i])
			this->_learnInventory[i] = to_copy._learnInventory[i]->clone();
		else
			this->_learnInventory[i] = NULL;
	}
	//std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource & MateriaSource::operator=(const MateriaSource& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_learnInventory[i])
				delete this->_learnInventory[i];
			if (src._learnInventory[i])
				this->_learnInventory[i] = src._learnInventory[i]->clone();
			else
				this->_learnInventory[i] = NULL;
		}
	}
	//std::cout << "MateriaSource assignement operator(=) called" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i])
			delete this->_learnInventory[i];
	}
	//std::cout << "MateriaSource default destructor called" << std::endl;
}

/*===Member Function===*/
void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i] == NULL)
		{
			this->_learnInventory[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i] && this->_learnInventory[i]->getType() == type)
			return (this->_learnInventory[i]->clone());
	}
	return (NULL);
}
