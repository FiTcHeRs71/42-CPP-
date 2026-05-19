#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <iostream>

class Animal
{
	private:
	

	protected:

	std::string	_type;

	public:

	/*===Canonical Form===*/
	Animal(void);
	virtual ~Animal(void);
	Animal(const Animal& to_copy);
	Animal&operator=(const Animal& src);

	/*===Other Constructor===*/
	Animal(std::string type);

	/*===Getters & Setters===*/
	std::string getType(void)const;

	/*===Member Function===*/
	virtual void	makeSound(void) const;
};

#endif