#include "ScalarConverte.hpp"

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
static void	convert(const std::string str)
{
	
}