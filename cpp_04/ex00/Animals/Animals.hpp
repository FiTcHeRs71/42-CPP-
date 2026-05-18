#ifndef __ANIMALS_HPP__
# define __ANIMALS_HPP__

# include <iostream>

class Animals
{
	private:
	

	protected:

	std::string	_type;

	public:

	/*===Canonical Form===*/
	Animals(void);
	~Animals(void);
	Animals(const Animals& to_copy);
	Animals&operator=(const Animals& src);

	/*===Other Constructor===*/
	Animals(std::string type);

	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	
};

#endif