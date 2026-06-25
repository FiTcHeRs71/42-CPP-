#include "PmergeMe.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cerrno>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

/*===Canonical Form===*/
PmergeMe::PmergeMe(void)
	:_hasStraggler(false)
	,_straggler(0)
{
	//std::cout << "PmergeMe default constructor called" << std::endl;
}
PmergeMe::~PmergeMe(void)
{
	//std::cout << "PmergeMe default destructor called" << std::endl;
}
PmergeMe::PmergeMe(const PmergeMe& to_copy)
	:_vector(to_copy._vector)
	,_pair(to_copy._pair)
	,_deque(to_copy._deque)
	,_hasStraggler(to_copy._hasStraggler)
	,_straggler(to_copy._straggler)
{
	//std::cout << "PmergeMe copy constructor called" << std::endl;
}
PmergeMe & PmergeMe::operator=(const PmergeMe& src)
{
	//std::cout << "PmergeMe assignement operator(=) constructor called" << std::endl;
	if (this != &src)
	{
		this->_vector = src._vector;
		this->_pair = src._pair;
		this->_deque = src._deque;
		this->_hasStraggler = src._hasStraggler;
		this->_straggler = src._straggler;
	}
		return (*this);
}

void	PmergeMe::solve(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		char* p_end = NULL;
		long value = std::strtol(argv[i], &p_end, 10);
		if (errno == ERANGE || *p_end != '\0' || value > INT_MAX || value < 0)
			throw InvalidArgs(std::string() + "Error : Invalid args -> " + argv[i]);
		this->_vector.push_back(value);
		this->_deque.push_back(value);
	}
	this->_hasStraggler = (this->_vector.size() % 2 == 0) ? false : true;
	for (size_t i = 0; i + 1 < this->_vector.size(); i += 2)
	{
		if (this->_vector[i] > this->_vector[i + 1])
			this->_pair.push_back(std::make_pair(this->_vector[i], this->_vector[i + 1]));
		else
			this->_pair.push_back(std::make_pair(this->_vector[i + 1], this->_vector[i]));
	}
	if (this->_hasStraggler)
		this->_straggler = this->_vector[this->_vector.size() - 1];
	sortVector(1);
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

}

void	PmergeMe::sortVector(size_t blockSize)
{
	size_t nbBlocks = this->_vector.size() / blockSize;
	if (nbBlocks < 2)
		return;
	for (size_t b = 0; b + 1 < nbBlocks; b += 2)
	{
		long last_a = this->_vector[b*blockSize + blockSize - 1];
		long last_b = this->_vector[(b+1)*blockSize + blockSize - 1];
		if (last_a > last_b)
			for (size_t k = 0; k < blockSize; k++)
				std::swap(this->_vector[b * blockSize + k], this->_vector[(b+1)*blockSize + k]);
	}
	sortVector(blockSize * 2);
	std::vector<size_t>	mainchain;
	std::vector<size_t>	pend;
	for (size_t p = 0; p < nbBlocks; p++)
	{
		size_t	start = p * blockSize;
		if (p % 2 == 0)
			pend.push_back(start);
		else
			mainchain.push_back(start);
	}
	std::vector<size_t>	result;
	result.push_back(pend[0]);
	for (size_t i = 0; i < mainchain.size(); i++)
	{
		result.push_back(mainchain[i]);
	}
	for(size_t f = 1; f < pend.size(); f++)
	{
		size_t low = 0;
		size_t high = result.size();
		long value = this->_vector[pend[f] + blockSize - 1];
		while (low < high) 
		{
			size_t medium = (low + high) / 2;
			if (this->_vector[result[medium] + blockSize - 1] < value)
				low = medium + 1;
			else
				high = medium;
		}
		result.insert(result.begin() + low, pend[f]);
	}
	std::vector<long>	sorted;
	for (size_t i = 0; i < result.size(); i++)
	{
		for (size_t k = 0; k < blockSize; k++)
			sorted.push_back(this->_vector[result[i] + k]);
	}
	for (size_t i = nbBlocks * blockSize; i < this->_vector.size(); i++)
		sorted.push_back(this->_vector[i]);
	this->_vector = sorted;
}
