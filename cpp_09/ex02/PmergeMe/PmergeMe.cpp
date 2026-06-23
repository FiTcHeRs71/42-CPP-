#include "PmergeMe.hpp"
#include <iostream>

/*===Canonical Form===*/
PmergeMe::PmergeMe(void)
{
	std::cout << "PmergeMe default constructor called" << std::endl;
}
PmergeMe::~PmergeMe(void)
{
	std::cout << "PmergeMe default destructor called" << std::endl;
}
PmergeMe::PmergeMe(const PmergeMe& to_copy)
{
	(void) to_copy;
	std::cout << "PmergeMe copy constructor called" << std::endl;
}
PmergeMe & PmergeMe::operator=(const PmergeMe& src)
{
	std::cout << "PmergeMe assignement operator(=) constructor called" << std::endl;
	(void)src;
	if (this != &src)
	{
		return (*this);
	}
		return (*this);
}

