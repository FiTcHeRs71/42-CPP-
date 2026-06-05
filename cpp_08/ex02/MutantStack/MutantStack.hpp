#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <ios>
#include <istream>
# include <stack>
# include <iostream>

template<class T>
class MutantStack : public std::stack<T>
{
	public:

	/*===Canonical Form===*/
	MutantStack(void);
	~MutantStack(void);
	MutantStack(const MutantStack& to_copy);
	MutantStack&operator=(const MutantStack& src);

	/*=== Typedef ===*/
	typedef typename MutantStack<T>::container_type::iterator iterator;

	/*===Member Function===*/

};

#endif /*MUTANTSTACK_HPP*/