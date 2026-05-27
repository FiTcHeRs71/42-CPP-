#include "ScalarConverte.hpp"
#include <cctype>
#include <cstddef>
#include <string>

static bool	isChar(const std::string str, size_t &len)
{
	if (len == 1 && !isdigit(str[0]))
		return (true);
	else if (len == 3 && str[0] == '\'' && str[2] == '\'')
		return (true);
	return (false);
}

static bool	isInt(const std::string str, size_t &len)
{
	size_t idx	= 0;

	if (str[0] == '+' || str[0] == '-')
		idx++;
	if (idx == len)
		return (false);
	while (idx < len)
	{
		if (!isdigit(str[idx]))
			return (false);
		idx++;
	}
	return (true);
}

static bool isSpecial(const std::string str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return (true);
	return (false);
}

static bool	isFloat(const std::string &str, size_t &len, size_t &dot)
{
	for (int j = dot - 1; j >= 0; j--)
	{
		if (!isdigit(str[j]) && j != 0)
			return (false);
		if (!isdigit(str[j]) && j == 0 && str[j] != '+' && str[j] != '-')
			return (false);
	}
	for (size_t i = dot + 1; i < len; i++)
	{
		if (!isdigit(str[i]) && str[i] != 'f')
			return (false);
		if (str[i] == 'f' && i != len - 1)
			return (false);
	}
	return (true);
}

e_type  whichType(const std::string &str, size_t &len)
{
	size_t	dot = str.find('.');
	size_t	f = str.find('f');

	if (dot == std::string::npos)
	{
		if (isChar(str, len))
			return (CHAR);
		else if (isInt(str, len))
			return (INT);
		else if (isSpecial(str))
			return (SPECIAL);
	}
	else
	{
		if (isFloat(str, len, dot))
		{
			if (f != std::string::npos)
				return (FLOAT);
			else
				return (DOUBLE);
		}
	}
	return (INVALID);
}
