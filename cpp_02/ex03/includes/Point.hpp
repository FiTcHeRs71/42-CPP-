#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:

	const Fixed	_x;
	const Fixed	_y;

	public:

	/*===Canonical Form===*/
	Point(void);
	~Point(void);
	Point(const float x, const float y);
	Point(const Point& to_copy);
	Point &operator=(const Point&);

	/*===Others===*/
	static Fixed	area(const Point &a, const Point &b, const Point &c);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif /*POINT_HPP*/