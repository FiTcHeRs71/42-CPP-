
#include "includes/harl.hpp"
#include <climits>
#include <cstdio>

int	main(void)
{
	std::string	input;
	Harl		harl;
	while(!std::cin.eof())
	{
		std::cout << "input > ";
		getline(std::cin, input);
		harl.complain(input);
	}
}