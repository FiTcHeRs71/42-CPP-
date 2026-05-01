
#include "../includes/Fixed.hpp"
#include <cmath>

const int	Fixed::_fracto_bits = 8;

Fixed::Fixed(void) : _fixed_p_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fixed_p_value(value * (1 << _fracto_bits))
{
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float value) : _fixed_p_value(roundf(value * (1 << _fracto_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed& new_one) : _fixed_p_value(new_one._fixed_p_value)
{
	std::cout << "Copy constructor called" << std::endl;
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