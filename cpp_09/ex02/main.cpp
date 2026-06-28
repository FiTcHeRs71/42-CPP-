#include "./pmergeMe/PmergeMe.hpp"
#include <bits/types/struct_timeval.h>
#include <exception>
#include <ostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error\nUsage: ./PmergeMe \"<numeric sequence>\"" << std::endl;
		return (1);
	}
	PmergeMe	PmergeMe;
	try
	{
		gettimeofday(&PmergeMe.start_time, NULL);
		PmergeMe.solve(argc, argv);
		std::cout << "Time to process a range of " << PmergeMe.getSizeOfVector()<< " elements with std::vector :" << &PmergeMe.end_vector - &PmergeMe.start_time << " us" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "/!\\ exception caught -> " << e.what() << std::endl;
		return (1);
	}
	return (0);
}