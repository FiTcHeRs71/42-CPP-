#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <iostream>

class PmergeMe
{
	private:

	std::vector<long>					_vector;
	std::deque<long>					_deque;


	protected:
	

	public:

	/*===Canonical Form===*/
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe(const PmergeMe& to_copy);
	PmergeMe&operator=(const PmergeMe& src);

	/*===Getters & Setters===*/
	

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