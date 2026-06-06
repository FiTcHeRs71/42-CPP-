#include "BitcoinExchange/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error\nUsage : ./btc <data.csv>" << std::endl;
		return (1);
	}
	std::ifstream	data("./data.csv");
	std::ifstream	infile(argv[1]);
	if (!data || !data.is_open() || !infile || !infile.is_open())
	{
		std::cerr << "Error : data/input not valid or could not be open" << std::endl;
		return (1);
	}
	if (data.peek() == std::ifstream::traits_type::eof() || infile.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Error : data/input is empty or invalid" << std::endl;
		data.close();
		return (1);
	}
	
	return (0);
}