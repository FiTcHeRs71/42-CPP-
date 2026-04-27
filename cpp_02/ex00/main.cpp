
#include "includes/Fixed.hpp"

int	main(void)
{
	Fixed a; // <-- Default constructor
	Fixed b( a ); // <-- Copy contructor
	Fixed c; // <-- Default constructor

	c = b; // <-- Assignement operator

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}