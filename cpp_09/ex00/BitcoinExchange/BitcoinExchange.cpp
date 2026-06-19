#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <iomanip>

/*===Canonical Form===*/
BitcoinExchange::BitcoinExchange(void)
{
	//std::cout << "BitcoinExchange default constructor called" << std::endl;
}
BitcoinExchange::~BitcoinExchange(void)
{
	//std::cout << "BitcoinExchange default destructor called" << std::endl;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& to_copy)
	:_database(to_copy._database)
{
	//std::cout << "BitcoinExchange copy constructor called" << std::endl;
}
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange& src)
{
	//std::cout << "BitcoinExchange assignement operator(=) constructor called" << std::endl;
	if (this != &src)
	{
		this->_database = src._database;
	}
	return (*this);
}

/*===Member Function===*/
void	BitcoinExchange::parse(const std::string &data, const std::string &infile)
{
	std::ifstream	inFile(infile.c_str());
	std::ifstream	inData(data.c_str());

	if (!inFile.is_open() || inFile.peek() == std::ifstream::traits_type::eof())
		throw AccessInfile();
	if (!inData.is_open() || inData.peek() == std::ifstream::traits_type::eof())
		throw AccessData();
	for (std::string line; std::getline(inData, line); )
	{
		if (line.empty() || line == "date,exchange_rate")
			continue;

		strtrim(line);

		size_t pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pos);
		std::string value = line.substr(pos + 1);

		strtrim(date);
		strtrim(value);

		std::stringstream str(value);
		double val;
		str >> val;

		if (isValidDate(date) && isValidValue(value))
			this->_database[date] = val;
	}
	for (std::string line; std::getline(inFile, line); )
	{
		if (line.empty() || line == "date | value")
			continue;

		strtrim(line);

		size_t pos = line.find('|');

		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pos);
		std::string value = line.substr(pos + 1);

		strtrim(date);
		strtrim(value);

		if (isValidDate(date) && isValidValueInput(value))
		{
			std::stringstream str(value);
			double val;
			str >> val;

			std::map<std::string, double>::iterator	it = this->_database.lower_bound(date);
			if (it != this->_database.end() && it->first == date)
			{
				std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << (val * it->second) << std::endl;
			}
			else if (it == this->_database.begin())
			{
				std::cerr << "Error : No date to estimate the value =>" << date << std::endl;
			}
			else
			{
				--it;
				std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << (val * it->second) << std::endl;
			}
		}
	}
}
