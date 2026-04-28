
#include "../includes/Fixed.hpp"

const int	Fixed::_fracto_bits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_p_value = value * (1 << _fracto_bits);
}
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_p_value = value * (1 << _fracto_bits);
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed& new_one)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_p_value = new_one._fixed_p_value;
}
std::ostream	&operator<<(std::ostream &flux, const Fixed& fixed)
{
	flux << fixed.toFloat();
	return (flux);
}

float	Fixed::toFloat(void)const
{
	return (static_cast<float>(this->_fixed_p_value) / (1 << _fracto_bits));
}
int		Fixed::toInt(void)const
{
	return (this->_fixed_p_value >> _fracto_bits);
}