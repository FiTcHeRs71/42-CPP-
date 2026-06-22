#include "./rpn/RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error\nUsage: ./RPN \"<athematical expression>\"" << std::endl;
		return (1);
	}
	RPN rpn;
	rpn.run(argv[1]);
	return (0);
}