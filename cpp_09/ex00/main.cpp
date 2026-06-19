#include "BitcoinExchange/BitcoinExchange.hpp"
#include <exception>
#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cerr << "Error\nUsage : ./btc <input.txt>" << std::endl;
		return (1);
	}
	BitcoinExchange	btc;
	try
	{
		btc.execute("./data.csv", argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << "/!\\ exception caught -> " << e.what() << std::endl;
		return (1);
	}
	return (0);
}