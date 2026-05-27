#include "./ScalarConverte/ScalarConverte.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error\nUsage : ./scalar <test>" << std::endl;
		return (1);
	}
	ScalarConverte convert;
	convert.convert(argv[1]);
	return (0);
}
