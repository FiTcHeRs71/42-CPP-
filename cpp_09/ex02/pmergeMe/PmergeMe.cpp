#include "PmergeMe.hpp"
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cerrno>
#include <iostream>
#include <string>
#include <vector>

/*===Canonical Form===*/
PmergeMe::PmergeMe(void)
{
	//std::cout << "PmergeMe default constructor called" << std::endl;
}
PmergeMe::~PmergeMe(void)
{
	//std::cout << "PmergeMe default destructor called" << std::endl;
}
PmergeMe::PmergeMe(const PmergeMe& to_copy)
	:_vector(to_copy._vector)
	,_deque(to_copy._deque)
{
	//std::cout << "PmergeMe copy constructor called" << std::endl;
}
PmergeMe & PmergeMe::operator=(const PmergeMe& src)
{
	//std::cout << "PmergeMe assignement operator(=) constructor called" << std::endl;
	if (this != &src)
	{
		this->_vector = src._vector;
		this->_deque = src._deque;
	}
		return (*this);
}

/*===Getters & Setters===*/
size_t	PmergeMe::getSizeOfVector(void)const
{
	return (this->_vector.size());
}

size_t	PmergeMe::getSizeOfDeque(void)const
{
	return (this->_deque.size());
}

void	PmergeMe::displayVector(void)
{
	display(this->_vector);
}

void	PmergeMe::displayDeque(void)
{
	display(this->_deque);
}

void	PmergeMe::check_args(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		char* p_end = NULL;
		errno = 0;
		long value = std::strtol(argv[i], &p_end, 10);
		if (errno == ERANGE || *p_end != '\0' || value > INT_MAX || value < 0)
			throw InvalidArgs(std::string() + "Error : Invalid args -> " + argv[i]);
	}
}

void	PmergeMe::fillVector(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		long value = std::strtol(argv[i], NULL, 10);
		this->_vector.push_back(value);
	}
}

void	PmergeMe::fillDeque(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		long value = std::strtol(argv[i], NULL, 10);
		this->_deque.push_back(value);
	}
}

void	PmergeMe::sortVector(void)
{
	sortContainer(this->_vector, 1);
}

void	PmergeMe::sortDeque(void)
{
	sortContainer(this->_deque, 1);
}

