#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <iostream>

class PmergeMe
{
	private:


	protected:
	

	public:

	/*===Canonical Form===*/
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe(const PmergeMe& to_copy);
	PmergeMe&operator=(const PmergeMe& src);

	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	void	solve(std::string args);
};

#endif