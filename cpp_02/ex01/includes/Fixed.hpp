#ifndef FIXED_HPP
# define FIXED_HPP

#include <fstream>
#include <iostream>

class Fixed
{
	private:

	int					_fixed_p_value;
	static const int	_fracto_bits;

	public:

	/*===Canonical Form===*/
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed(void);
	Fixed(const Fixed& new_one);

	/*===Member Function===*/
	float	toFloat(void)const;
	int		toInt(void)const;
};
std::ostream	&operator<<(std::ostream &flux, const Fixed& fixed);

#endif