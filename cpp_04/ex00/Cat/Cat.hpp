#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "../Animal/Animal.hpp"

class Cat : public Animal
{
	private:
	

	protected:
	

	public:

	/*===Canonical Form===*/
	Cat(void);
	~Cat(void);
	Cat(const Cat& to_copy);
	Cat&operator=(const Cat& src);

	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	virtual void	makeSound(void) const;
};

#endif