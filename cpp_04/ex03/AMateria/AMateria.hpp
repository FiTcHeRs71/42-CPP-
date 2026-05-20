#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

# include <iostream>
# include "../ICharacter/ICharacter.hpp"

class AMateria
{
	private:
	

	protected:

	std::string	_type;

	public:

	/*===Canonical Form===*/
	AMateria(void);
	~AMateria(void);
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


#endif /*__AMATERIA_HPP__*/