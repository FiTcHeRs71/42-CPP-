#ifndef NUTANTSTACK_HPP
# define  NUTANTSTACK_HPP

# include <iostream>
# include <stack>

/*===Canonical Form===*/
template<typename T>
MutantStack<T>::MutantStack(void)
	:std::stack<T>()
{
	std::cout << "MutantStack default constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << "MutantStack default destructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& to_copy)
	:std::stack<T>(to_copy)
{
	std::cout << "MutantStack copy constructor called" << std::endl;
}

template<typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack& src)
{
	std::cout << "MutantStack operator assignement(=) called" << std::endl;
	if (this != &src)
	{
		std::stack<T>::operator=(src);
	}
	return (*this);
}

/*===Member Function===*/
template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}

#endif /* MUTANTSTACK_HPP*/