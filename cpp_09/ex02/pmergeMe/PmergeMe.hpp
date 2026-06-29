#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstddef>
# include <deque>
# include <stdexcept>
# include <string>
# include <vector>
# include <iostream>
# include <sys/time.h>
# include <algorithm>

class PmergeMe
{
	private:

	std::vector<long>	_vector;
	std::deque<long>	_deque;

	public:

	struct timeval	start_time;
	struct timeval	end_time;

	/*===Canonical Form===*/
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe(const PmergeMe& to_copy);
	PmergeMe&operator=(const PmergeMe& src);

	/*===Getters & Setters===*/
	size_t	getSizeOfVector(void)const;
	size_t	getSizeOfDeque(void)const;

	/*===Member Function===*/
	void	check_args(int argc, char **args);
	void	fillVector(int argc, char **args);
	void	fillDeque(int argc, char **args);
	void	sortVector(void);
	void	sortDeque(void);
	void	displayVector(void);
	void	displayDeque(void);

	/*===Exception===*/
	class InvalidArgs : public std::runtime_error 
	{
		public:
		explicit InvalidArgs(const std::string& message) 
			: std::runtime_error(message) {}

		explicit InvalidArgs(const char* message) 
			: std::runtime_error(message) {}
	};

	/*===templates===*/
	template <typename C>
	void	display(C &container)
	{
		for (size_t i = 0; i < container.size(); i++)
			std::cout << container[i] << " ";
	}

	template <typename C>
	void sortContainer(C& container, size_t blockSize)
	{
		size_t nbBlocks = container.size() / blockSize;

		if (nbBlocks < 2)
			return;

		for (size_t b = 0; b + 1 < nbBlocks; b += 2)
		{
			long last_a = container[b*blockSize + blockSize - 1];
			long last_b = container[(b+1)*blockSize + blockSize - 1];
			if (last_a > last_b)
				for (size_t k = 0; k < blockSize; k++)
					std::swap(container[b * blockSize + k], container[(b+1)*blockSize + k]);
		}

		sortContainer(container,blockSize * 2);

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
			result.push_back(mainchain[i]);

		std::vector<size_t>	order;
		size_t	prev = 1;
		size_t	jac = 3;
		while (prev < pend.size())
		{
			size_t hi = (jac < pend.size()) ? jac : pend.size();
			for (size_t i = hi; i > prev; i--)
				order.push_back(i - 1);
			size_t	next = jac + 2 * prev;
			prev = jac;
			jac = next;
		}

		for(size_t o = 0; o < order.size(); o++)
	{
		size_t f = order[o];
		size_t low = 0;
		size_t high;
		if (f < mainchain.size())
		{
			high = 0;
			while (result[high] != mainchain[f])
				high ++;
		}
		else
			high = result.size();
		long value = container[pend[f] + blockSize - 1];
		while (low < high)
		{
			size_t medium = (low + high) / 2;
			if (container[result[medium] + blockSize - 1] < value)
				low = medium + 1;
			else
				high = medium;
		}
		result.insert(result.begin() + low, pend[f]);
	}

	C	sorted;
	for (size_t i = 0; i < result.size(); i++)
	{
		for (size_t k = 0; k < blockSize; k++)
			sorted.push_back(container[result[i] + k]);
	}
	for (size_t i = nbBlocks * blockSize; i < container.size(); i++)
		sorted.push_back(container[i]);
	container = sorted;
	}
};

#endif