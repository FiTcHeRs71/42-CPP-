
#include "../includes/Fixed.hpp"

const int	_fracto_bits = 8;

/*===Canonical Form===*/
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


/*===Getters & Setters===*/
int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed_p_value;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_p_value = raw;
}


/*===Assignment operator===*/
bool	Fixed::operator>(const Fixed& other) const
{
	if (this->_fixed_p_value > other._fixed_p_value)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& other) const
{
	if (this->_fixed_p_value < other._fixed_p_value)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	if (this->_fixed_p_value >= other._fixed_p_value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	if (this->_fixed_p_value <= other._fixed_p_value)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& other) const
{
	if (this->_fixed_p_value == other._fixed_p_value)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	if (this->_fixed_p_value != other._fixed_p_value)
		return (true);
	return (false);
}

int		Fixed::operator+(const Fixed& other) const
{
	return (this->_fixed_p_value + other._fixed_p_value);
}

int		Fixed::operator-(const Fixed& other) const
{
	return (this->_fixed_p_value - other._fixed_p_value);
}

int		Fixed::operator*(const Fixed& other) const
{
	return (this->_fixed_p_value * other._fixed_p_value);
}

int		Fixed::operator/(const Fixed& other) const
{
	return (this->_fixed_p_value / other._fixed_p_value);
}

Fixed&	Fixed ::operator++(void)
{
	++(this->_fixed_p_value);
	return(*this);
}

Fixed	Fixed ::operator++(int)
{
	Fixed tmp(*this);

	++(this->_fixed_p_value);
	return(tmp);
}

Fixed&	Fixed ::operator--(void)
{
	--(this->_fixed_p_value);
	return(*this);
}

Fixed	Fixed ::operator--(int)
{
	Fixed tmp(*this);

	--(this->_fixed_p_value);
	return(tmp);
}

/*===Others===*/
float	Fixed::toFloat(void)const
{
	return (static_cast<float>(this->_fixed_p_value) / (1 << _fracto_bits));
}

int		Fixed::toInt(void)const
{
	return (this->_fixed_p_value >> _fracto_bits);
}

Fixed&	Fixed::min(Fixed & to_comp1, Fixed & to_comp2)
{
	if (to_comp1._fixed_p_value < to_comp2._fixed_p_value)
		return (to_comp1);
	return (to_comp2);
}

const Fixed&	Fixed::min(const Fixed & to_comp1, const Fixed & to_comp2)
{
	if (to_comp1._fixed_p_value < to_comp2._fixed_p_value)
		return (to_comp1);
	return (to_comp2);
}

Fixed & Fixed::max(Fixed & to_comp1, Fixed & to_comp2)
{
	if (to_comp1._fixed_p_value < to_comp2._fixed_p_value)
		return (to_comp1);
	return (to_comp2);
}

Fixed const & Fixed::max(const Fixed & to_comp1, const Fixed & to_comp2)
{
	if (to_comp1._fixed_p_value < to_comp2._fixed_p_value)
		return (to_comp1);
	return (to_comp2);
}