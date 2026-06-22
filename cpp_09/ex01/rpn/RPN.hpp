#ifndef RNP_HPP
# define RNP_HPP

# include <list>
#include <iostream>

class RPN
{
	private:

	std::list<long>	_list;

	protected:
	

	public:

	/*===Canonical Form===*/
	RPN(void);
	~RPN(void);
	RPN(const RPN& to_copy);
	RPN&operator=(const RPN& src);

	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	void	run(std::string args);
};

#endif /*RNP_HPP*/