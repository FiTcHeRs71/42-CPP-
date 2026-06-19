#include "./RPN.hpp"

/*===Canonical Form===*/
RPN::RPN(void)
{

}
RPN::~RPN(void)
{

}
RPN::RPN(const RPN& to_copy)
	:_list(to_copy._list)
{

}
RPN & RPN::operator=(const RPN& src)
{
	if (this != &src)
	{
		this->_list = src._list;
	}
	return (*this);
}