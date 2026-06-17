#include "BitcoinExchange.hpp"

	/*===Canonical Form===*/
BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}
BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "BitcoinExchange default destructor called" << std::endl;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& to_copy)
{
	(void)to_copy;
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
}
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
	{

	}
	return (*this);
}

	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	