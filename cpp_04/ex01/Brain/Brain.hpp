#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <iostream>

class Brain
{
	private:

	std::string	_ideas[100];

	protected:
	

	public:

	/*===Canonical Form===*/
	Brain(void);
	virtual ~Brain(void);
	Brain(const Brain& to_copy);
	Brain&operator=(const Brain& src);

	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	
};


#endif /*__BRAIN_HPP__*/