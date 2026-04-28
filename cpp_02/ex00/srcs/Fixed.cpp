
#include "../includes/Fixed.hpp"

const int Fixed::_fracto_value = 8;

/*===Canonical Form===*/
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &in_fixed) // <-- Copy contructor
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = in_fixed._value;
}

Fixed & Fixed::operator=(const Fixed& in_fixed) // <-- Assignement operator
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &in_fixed)
	{
		this->_value = in_fixed._value;
	}
	return (*this);
}

/*===Getters & Setters===*/
int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}
