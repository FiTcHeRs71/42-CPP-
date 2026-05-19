#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <iostream>

class Brain
{
	private:

	protected:

	std::string	_ideas[100];

	public:

	/*===Canonical Form===*/
	Brain(void);
	virtual ~Brain(void);
	Brain(const Brain& to_copy);
	Brain&operator=(const Brain& src);

	/*===Getters & Setters===*/
	std::string getIdeas(int index)const;

	/*===Member Function===*/
	
};


#endif /*__BRAIN_HPP__*/