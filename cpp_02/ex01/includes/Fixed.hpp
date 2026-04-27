#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:

	

	public:

	Fixed(void); // <-- Default constructor
	~Fixed(void); // <-- Default Destructor
	Fixed(const Fixed &in_fixed); // <-- Copy contructor
	Fixed &operator=(const Fixed &in_fixed); // <-- Assignement operator

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif