#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

# include <iostream>
# include "../ICharacter/ICharacter.hpp"

class IMateriaSource
{
	public:

	/*===Member Function===*/
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

class AMateria
{
	private:
	

	protected:

	std::string	_type;

	public:

	/*===Canonical Form===*/
	AMateria(void);
	virtual ~AMateria(void);
	AMateria(const AMateria& to_copy);
	AMateria&operator=(const AMateria& src);

	/*===Others constructor===*/
	AMateria(std::string const & type);

	/*===Getters & Setters===*/
	std::string const & getType()const;

	/*===Member Function===*/
	virtual AMateria* clone() const = 0;
	virtual void	use(ICharacter& target);
};

class MateriaSource : public IMateriaSource
{
	private:

	AMateria	*_learnInventory[4];

	protected:



	public:

	/*===Canonical Form===*/
	MateriaSource(void);
	virtual ~MateriaSource(void);
	MateriaSource(const MateriaSource& to_copy);
	MateriaSource&operator=(const MateriaSource& src);

	/*===Member Function===*/
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};

#endif /*__AMATERIA_HPP__*/