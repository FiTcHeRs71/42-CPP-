#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "../Animal/Animal.hpp"

class Dog : public Animal
{
	private:
	

	protected:
	

	public:

	/*===Canonical Form===*/
	Dog(void);
	~Dog(void);
	Dog(const Dog& to_copy);
	Dog&operator=(const Dog& src);

	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	virtual void	makeSound(void) const;
};

#endif