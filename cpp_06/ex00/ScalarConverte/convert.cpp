#include "ScalarConverte.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <math.h>

void	convertChar(const std::string& str, size_t& len)
{
	char	c = 0;

	if (len == 1)
		c = str[0];
	else
		c = str[1];

	std::cout << "char: ";
	if (isprint(static_cast<unsigned char>(c)))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
		<< static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1)
		<< static_cast<double>(c) << std::endl;
}

void	convertInt(const std::string& str)
{
	errno = 0;
	long	int_converted = strtol(str.c_str(), NULL, 10);

	if (int_converted > INT_MAX || int_converted < INT_MIN || errno == ERANGE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	int		nb = static_cast<int>(int_converted);

	std::cout << "char: ";
	if (!isascii(nb))
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<unsigned char>(nb)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(nb) << "'" << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
		<< static_cast<float>(nb) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1)
		<< static_cast<double>(nb) << std::endl;
}

void	convertFloat(const std::string& str)
{
	float	float_converted = (float)atof(str.c_str());

	std::cout << "char: ";
	if (!isascii(float_converted))
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<unsigned char>(float_converted)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(float_converted) << "'" << std::endl;
	std::cout << "int: ";
	if (float_converted > static_cast<float>(INT_MAX) || float_converted < static_cast<float>(INT_MIN))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(float_converted) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << float_converted << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(float_converted) << std::endl;
}

void	convertDouble(const std::string& str)
{
	double	double_converted = atof(str.c_str());

		std::cout << "char: ";
	if (!isascii(double_converted))
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<unsigned char>(double_converted)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(double_converted) << "'" << std::endl;
	std::cout << "int: ";
	if (double_converted > static_cast<double>(INT_MAX) || double_converted < static_cast<double>(INT_MIN))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(double_converted) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(double_converted) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << double_converted << std::endl;
}

void	printSpecial(const std::string& str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}
