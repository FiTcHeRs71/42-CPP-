#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <bits/types/struct_timeval.h>
#include <cstddef>
#include <deque>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <sys/time.h>

class PmergeMe
{
	private:

	std::vector<long>	_vector;
	std::deque<long>	_deque;


	protected:
	

	public:

	struct timeval	start_time;
	struct timeval	end_vector;
	struct timeval	end_dque;

	/*===Canonical Form===*/
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe(const PmergeMe& to_copy);
	PmergeMe&operator=(const PmergeMe& src);

	/*===Getters & Setters===*/
	size_t	getSizeOfVector(void)const;

	/*===Member Function===*/
	void	solve(int argc, char **args);
	void	sortVector(size_t blockSize);

	/*===Exception===*/
	class InvalidArgs : public std::runtime_error 
	{
		public:
		explicit InvalidArgs(const std::string& message) 
			: std::runtime_error(message) {}

		explicit InvalidArgs(const char* message) 
			: std::runtime_error(message) {}
	};
};

#endif