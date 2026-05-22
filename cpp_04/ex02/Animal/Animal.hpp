#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <iostream>

class Animal
{
	private:
	

	protected:

	Animal(void);
	Animal(const Animal& to_copy);
	Animal&operator=(const Animal& src);

	std::string	_type;

	public:

	/*===Canonical Form===*/
	virtual ~Animal(void);

	/*===Other Constructor===*/
	Animal(std::string type);

	/*===Getters & Setters===*/
	std::string getType(void)const;

	/*===Member Function===*/
	virtual void	makeSound(void) const = 0;
};

#endif