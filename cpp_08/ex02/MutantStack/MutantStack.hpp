#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
template<class T>
class MutantStack
{
	private:

	std::stack<T>

	protected:
	

	public:

	/*===Canonical Form===*/
	MutantStack(void);
	~MutantStack(void);
	MutantStack(const MutantStack& to_copy);
	MutantStack&operator=(const MutantStack& src);

	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	
};

#endif /*MUTANTSTACK_HPP*/