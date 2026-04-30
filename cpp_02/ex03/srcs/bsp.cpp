
#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	total = Point::area(a, b, c);
	Fixed	area_abp = Point::area(a, b, point);
	Fixed	area_acp = Point::area(a, point, c);
	Fixed	area_bcp = Point::area(point, b, c);

	if (area_abp == Fixed(0) || area_acp == Fixed(0) || area_bcp == Fixed(0))
		return (false);
	if (total != area_abp + area_acp + area_bcp)
		return (false);
	return (true);
}