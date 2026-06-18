#include "BitcoinExchange.hpp"

/*===Canonical Form===*/
BitcoinExchange::BitcoinExchange(void)
{
	//std::cout << "BitcoinExchange default constructor called" << std::endl;
}
BitcoinExchange::~BitcoinExchange(void)
{
	//std::cout << "BitcoinExchange default destructor called" << std::endl;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& to_copy)
	:_data(to_copy._data)
	,_infile(to_copy._infile)
{
	(void)to_copy;
	//std::cout << "BitcoinExchange copy constructor called" << std::endl;
}
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
	{
		this->_data = src._data;
		this->_infile = src._infile;
	}
	return (*this);
}

BitcoinExchange(std::ifstream &data, std::ifstream &infile)
	:_infile(infile)
	,_data(data)
{
	//std::cout << "BitcoinExchange full constructor called" << std::endl;
}

/*===Getters & Setters===*/
	

/*===Member Function===*/
	