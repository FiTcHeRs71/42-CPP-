#include "./rpn/RPN.hpp"
#include <exception>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error\nUsage: ./RPN \"<athematical expression>\"" << std::endl;
		return (1);
	}
	RPN rpn;
	try
	{
		rpn.run(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << "/!\\ exception caught -> " << e.what() << std::endl;
		return (1);
	}
	return (0);
}