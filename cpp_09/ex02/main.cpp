#include "./pmergeMe/PmergeMe.hpp"
#include <exception>
#include <ostream>

double	time_diff(const timeval &start, const timeval &end)
{
	double	diff;

	diff = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
	return (diff);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error\nUsage: ./PmergeMe \"<numeric sequence>\"" << std::endl;
		return (1);
	}
	std::cout << "Before : ";
	for(size_t i = 1; argv[i]; i++)
	{
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
	try
	{
		PmergeMe	PmergeMe;
		double		vector_timer;
		double		deque_timer;

		PmergeMe.check_args(argc, argv);
		gettimeofday(&PmergeMe.start_time, NULL);
		PmergeMe.fillVector(argc, argv);
		PmergeMe.sortVector();
		gettimeofday(&PmergeMe.end_time, NULL);
		vector_timer = time_diff(PmergeMe.start_time, PmergeMe.end_time);
		
		gettimeofday(&PmergeMe.start_time, NULL);
		PmergeMe.fillDeque(argc, argv);
		PmergeMe.sortDeque();
		gettimeofday(&PmergeMe.end_time, NULL);
		deque_timer = time_diff(PmergeMe.start_time, PmergeMe.end_time);

		std::cout << "Vector after : ";
		PmergeMe.displayVector();
		std::cout << std::endl;

		std::cout << "Deque after : ";
		PmergeMe.displayDeque();
		std::cout << std::endl;

		std::cout << "Time to process a range of " << PmergeMe.getSizeOfVector()<< " elements with std::vector : " << vector_timer << " us" << std::endl;
		std::cout << "Time to process a range of " << PmergeMe.getSizeOfDeque() << " elements with std::deque : " << deque_timer << " us" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "/!\\ exception caught -> " << e.what() << std::endl;
		return (1);
	}
	return (0);
}