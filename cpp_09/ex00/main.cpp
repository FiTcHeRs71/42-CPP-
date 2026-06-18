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
	BitcoinExchange	btc ();
	try
	{
		btc.run(data, infile);
	}
	catch (std::exception &e)
	{
	}
	return (0);
}