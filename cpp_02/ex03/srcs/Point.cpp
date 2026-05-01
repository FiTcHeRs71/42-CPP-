
#include "../includes/Point.hpp"

/*===Canonical Form===*/

Point::Point(void) : _x(0), _y(0)
{
	std::cout << "Point default constructor called" << std::endl;
}

Point::~Point(void)
{
	std::cout << "Point destructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	std::cout << "Point Float constructor called" << std::endl;
}

Point::Point(const Point& to_copy) : _x(to_copy._x), _y(to_copy._y)
{
	std::cout << "Point copy constructor called" << std::endl;
}

Point& Point::operator=(const Point&)
{
	std::cout << "Point copy assignment operator called" << std::endl;
	return (*this);
}


/*===Others===*/
Fixed	Point::area(const Point &a, const Point &b, const Point &c)
{
	Fixed	area = (a._x * (b._y - c._y) + b._x * (c._y - a._y) + c._x * (a._y - b._y));
	if (area < Fixed(0))
		area = Fixed(0) - area;
	return (area);
}