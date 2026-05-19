#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "../Animal/Animal.hpp"
# include "../Brain/Brain.hpp"

class Dog : public Animal
{
	private:

	Brain*	_myBrain;

	protected:
	

	public:

	/*===Canonical Form===*/
	Dog(void);
	~Dog(void);
	Dog(const Dog& to_copy);
	Dog&operator=(const Dog& src);

	/*===Getters & Setters===*/
	std::string		getMyBrainIdeas(int index) const;

	/*===Member Function===*/
	virtual void	makeSound(void) const;
};

#endif