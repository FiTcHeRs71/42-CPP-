#include "Animals.hpp"

	/*===Canonical Form===*/
Animals::Animals(void)
	: _type("Generic Animals")
{
	std::cout << "Animals default constructor called" << std::endl;
}

Animals::~Animals(void)
{
	std::cout << "Animals default destructor called" << std::endl;
}

Animals & Animals::operator=(const Animals& src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	return(*this);
	std::cout << "Animals assignement operator called" << std::endl;
}

Animals::Animals(const Animals& to_copy)
	:_type(to_copy._type)
{
	std::cout << "Animals copy constructor called" << std::endl;
}

/*===Other Constructor===*/
Animals::