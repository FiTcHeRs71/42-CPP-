#include "ScalarConverte.hpp"
#include <cstddef>
#include <ctime>

/*===Canonical Form===*/
ScalarConverte::ScalarConverte(void)
{
	std::cout << "ScalarConverte default constructor called" << std::endl;
}

ScalarConverte::~ScalarConverte(void)
{
	std::cout << "ScalarConverte default destructor called" << std::endl;
}

ScalarConverte::ScalarConverte(const ScalarConverte& to_copy)
{
	std::cout << "ScalarConverte copy constructor called" << std::endl;
	*this = to_copy;
}

ScalarConverte & ScalarConverte::operator=(const ScalarConverte& src)
{
	std::cout << "ScalarConverte operator assignement(=) called" << std::endl;
	if (this != &src)
	{
		return (*this);
	}
	return (*this);
}

/*===Member Function===*/
void	ScalarConverte::convert(const std::string str)
{
	size_t	len = str.length();
	e_type	type = whichType(str, len);

	switch (type)
	{
		case INVALID :
			std::cout << "Invalid input" << std::endl;
			break;
		case CHAR :
			convertChar(str, len);
			break;
		case SPECIAL :
			printSpecial(str);
			break;
		case INT :
			convertInt(str);
			break;
		case FLOAT:
			convertFloat(str);
			break;
		case DOUBLE :
			convertDouble(str);
			break;
	}
}
