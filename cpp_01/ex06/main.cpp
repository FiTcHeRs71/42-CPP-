
#include "includes/harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc < 2)
	{
		std::cout << "What a pleasure, no problem under the sun" << std::endl;
		return (0);
	}
	else
	{
		harl.complain(argv[1]);
	}
}