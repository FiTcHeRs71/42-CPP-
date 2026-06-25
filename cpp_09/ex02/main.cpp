#include "./pmergeMe/PmergeMe.hpp"
#include <exception>

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
		PmergeMe.solve(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << "/!\\ exception caught -> " << e.what() << std::endl;
		return (1);
	}
	return (0);
}