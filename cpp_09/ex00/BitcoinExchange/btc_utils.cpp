#include "./BitcoinExchange.hpp"
#include <algorithm>
#include <cctype>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <iterator>

void	strtrim(std::string &line)
{
	const std::string whiteSpace = "\t\n \r";
	size_t pos_start = line.find_first_not_of(whiteSpace);
	if (pos_start == std::string::npos)
	{
		line = "";
		return;
	}
	size_t pos_end = line.find_last_not_of(whiteSpace);
	line = line.substr(pos_start, pos_end - pos_start + 1);
}

bool	isLeap(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool isValidDate(const std::string &line)
{
	size_t pos_start = line.find_first_of("-");
	size_t pos_end = line.find_last_of("-");

	if (pos_start == std::string::npos || pos_start == pos_end)
	{
		std::cerr << "Error: bad date format => " << line << std::endl;
		return (false);
	}

	int year = std::atoi(line.substr(0, pos_start).c_str());
	int month = std::atoi(line.substr(pos_start + 1, pos_end - pos_start - 1).c_str());
	int day = std::atoi(line.substr(pos_end + 1).c_str());

	if (year > YEAR_MAX || year < YEAR_MIN)
	{
		std::cerr << "Error: bad date => " << line << std::endl;
		return (false);
	}
	if (month < 1 || month > 12) 
	{
		std::cerr << "Error: bad date => " << line << std::endl;
		return (false);
	}
	if (day < 1 || day > 31)
	{
		std::cerr << "Error: bad date => " << line << std::endl;
		return (false);
	}
	if (month == 2)
	{
		if (isLeap(year))
		{
			if (day > 29)
			{
				std::cerr << "Error: bad date => " << line << std::endl;
				return (false);
			}
		}
		else if (day > 28)
		{
			std::cerr << "Error: bad date => " << line << std::endl;
			return (false);
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
		{
			std::cerr << "Error: bad date => " << line << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	isValidValue(std::string &line)
{
	if (line.empty())
	{
		std::cerr << "Error: invalid value => " << line << std::endl;
		return (false);
	}
	if (!std::for_each(line.begin(), line.end(), isdigit))
	{
		std::cerr << "Error: invalid value => " << line << std::endl;
		return (false);
	}
	if (std::atol(line.c_str()) > INT_MAX)
	{
		std::cerr << "Error: too large number => " << line << std::endl;
		return (false);
	}
	if (std::atol(line.c_str()) < 0)
	{
		std::cerr << "Error: not a positive number => " << line << std::endl;
		return (false);
	}
	return (true);
}
