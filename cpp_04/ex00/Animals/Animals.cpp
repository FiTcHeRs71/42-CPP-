#include "Animals.hpp"

Animals::Animals(void)
	: _type("Generic Animals")
{
	std::cout << "Animals default constructor called" << std::endl;
}

Animals::~Animals(void)
{
	std::cout << "Animals default destructor called" << std::endl;
}