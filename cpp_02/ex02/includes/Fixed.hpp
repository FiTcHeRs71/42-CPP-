#ifndef FIXED_HPP
# define FIXED_HPP

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

	/*===Assignment operator===*/
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	int operator+(const Fixed& other) const;
	int operator-(const Fixed& other) const;
	int operator/(const Fixed& other) const;
	int operator*(const Fixed& other) const;
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);
	Fixed &operator=(const Fixed &in_fixed);

	/*===Getters & Setters===*/
	int						getRawBits( void ) const;
	void					setRawBits( int const raw );

	/*===Member Function===*/
	float					toFloat(void)const;
	int						toInt(void)const;
	static const Fixed&		max(const Fixed & to_comp1, const Fixed & to_comp2);
	static const Fixed&		min(const Fixed & to_comp1, const Fixed & to_comp2);
	static Fixed&			max(Fixed & to_comp1, Fixed & to_comp2);
	static Fixed&			min(Fixed & to_comp1, Fixed & to_comp2);
};

std::ostream				&operator<<(std::ostream &flux, const Fixed& fixed);

#endif