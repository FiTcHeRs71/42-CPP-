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

	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	
};

#endif