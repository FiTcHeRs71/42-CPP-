#ifndef __ICE_CURE_HPP__
# define __ICE_CURE_HPP__

#include <iostream>
#include "../AMateria/AMateria.hpp"

class Ice : public AMateria
{
	public:

	/*===Canonical Form===*/
	Ice(void);
	~Ice(void);
	Ice(const Ice& to_copy);
	Ice&operator=(const Ice& src);

	/*===Member Function===*/
	virtual AMateria*	clone() const;
	void				use(ICharacter& target);
};

class Cure : public AMateria
{
	public:

	/*===Canonical Form===*/
	Cure(void);
	~Cure(void);
	Cure(const Cure& to_copy);
	Cure&operator=(const Cure& src);

	/*===Member Function===*/
	virtual AMateria*	clone() const;
	void				use(ICharacter& target);

};

#endif /*__ICE_CURE_HPP__*/