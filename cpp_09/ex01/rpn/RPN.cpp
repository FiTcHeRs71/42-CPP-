#include "./RPN.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>

/*===Canonical Form===*/
RPN::RPN(void)
{
	std::cout << "RPN default constructor called" << std::endl;
}
RPN::~RPN(void)
{
	std::cout << "RPN default destructor called" << std::endl;
}
RPN::RPN(const RPN& to_copy)
	:_list(to_copy._list)
{
	std::cout << "RPN copy constructor called" << std::endl;
}
RPN & RPN::operator=(const RPN& src)
{
	std::cout << "RPN oprator assignement(=) constructor called" << std::endl;
	if (this != &src)
	{
		this->_list = src._list;
	}
	return (*this);
}

void	RPN::run(std::string args)
{
	long num;

	for (int i = 0; args[i]; i++)
	{
		if (std::isdigit(args[i]))
		{
			std::stringstream ss;
			ss << args[i];
			ss >> num;
			this->_list.push_back(num);
			std::cout << "List elements: ";
			std::copy(this->_list.begin(), this->_list.end(), std::ostream_iterator<long>(std::cout, " "));
			std::cout << std::endl;
		}
	}
}