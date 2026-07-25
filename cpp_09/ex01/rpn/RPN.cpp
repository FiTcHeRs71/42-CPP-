#include "./RPN.hpp"
#include <iostream>
#include <cctype>


/*===Canonical Form===*/
RPN::RPN(void)
{
	//std::cout << "RPN default constructor called" << std::endl;
}
RPN::~RPN(void)
{
	//std::cout << "RPN default destructor called" << std::endl;
}
RPN::RPN(const RPN& to_copy)
	:_list(to_copy._list)
{
	//std::cout << "RPN copy constructor called" << std::endl;
}
RPN & RPN::operator=(const RPN& src)
{
	//std::cout << "RPN oprator assignement(=) constructor called" << std::endl;
	if (this != &src)
	{
		this->_list = src._list;
	}
	return (*this);
}

void	RPN::run(std::string args)
{
	for (int i = 0; args[i]; i++)
	{
		if (args[i] == ' ')
			continue;
		else if (std::isdigit(args[i]))
		{
			this->_list.push(static_cast<double>(args[i] - '0'));
		}
		else if (args[i] == '+' || args[i] == '-' || args[i] == '*' || args[i] == '/')
		{
			double  a = popVal();
			double  b = popVal();
			switch (args[i])
			{
				case '+' : this->_list.push(b + a); break;
				case '-' : this->_list.push(b - a); break;
				case '*' : this->_list.push(b * a); break;
				case '/' :
					if (a == 0)
						throw DivisionByZero();
				this->_list.push(b / a);
				break;
			}
		}
		else
			throw InvalidToken();
	}
	if (this->_list.size() != 1)
		throw InvalidExpression();
	std::cout << this->_list.top() << std::endl;
}


double	RPN::popVal(void)
{
	double	element_stack;

	if (this->_list.empty())
		throw InvalidStackSize();
	element_stack = this->_list.top();
	this->_list.pop();
	return (element_stack);
}